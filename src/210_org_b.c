/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   210_org_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:54:52 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 16:41:27 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_b_chunks(t_root *r, t_split_chunk *dest)
{
	int	rotated_down_a;
	int	rotated_down_b;

	rotated_down_b = dest->min->size;
	rotated_down_a = dest->med->size;
	while (rotated_down_a > 0 || rotated_down_b > 0)
	{
		if (rotated_down_a > 0 && rotated_down_b > 0)
		{
			rrr(r->a, r->b);
			rotated_down_a--;
			rotated_down_b--;
		}
		else if (rotated_down_a > 0)
		{
			rra(r->a);
			rotated_down_a--;
		}
		else if (rotated_down_b > 0)
		{
			rrb(r->b);
			rotated_down_b--;
		}
	}
}

void	push_mini_chunks_b_helper(t_root *r, t_split_chunk *dest, int mediane2)
{
	if (r->b->array[0] < mediane2)
	{
		rb(r->b);
		dest->min->size++;
	}
	else
	{
		pa(r->a, r->b);
		ra(r->a);
		dest->med->size++;
	}
}

void	push_mini_chunks_b(t_root *r, t_chunk *chunk, t_split_chunk *dest)
{
	int	i;
	int	mediane;
	int	mediane2;

	mediane = get_mediane(r->b, chunk->size, 1);
	mediane2 = get_mediane(r->b, chunk->size, 3);
	i = -1;
	while (++i < chunk->size)
	{
		if (r->b->array[0] < mediane)
			push_mini_chunks_b_helper(r, dest, mediane2);
		else
		{
			pa(r->a, r->b);
			dest->max->size++;
		}
	}
}
