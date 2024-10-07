/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   220_split_chunk_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:40:43 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/05 15:52:46 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_mini_chunks(t_root *r, t_split_chunk *dest, int pushed_down)
{
	int	rotated_down_a;
	int	rotated_down_b;

	rotated_down_a = pushed_down;
	rotated_down_b = dest->med->size;
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

void	rotate_mc_back(t_root *r, int nr_elems)
{
	int	i;

	i = 0;
	while (i < nr_elems)
	{
		pa(r->a, r->b);
		i++;
	}
}

void	push_mini_chunks_a_helper(t_root *r, t_split_chunk *dest, int mediane2)
{
	pb(r->a, r->b);
	if (r->b->array[0] < mediane2)
		dest->min->size++;
	else
	{
		rb(r->b);
		dest->med->size++;
	}
}

void	push_mini_chunks_a(t_root *r, t_chunk *chunk, t_split_chunk *dest)
{
	int	i;
	int	mediane;
	int	mediane2;
	int	pushed_down;

	i = -1;
	pushed_down = 0;
	mediane = get_mediane(r->a, chunk->size, 0);
	mediane2 = get_mediane(r->a, chunk->size, 2);
	while (++i < chunk->size)
	{
		if (r->a->array[0] < mediane)
			push_mini_chunks_a_helper(r, dest, mediane2);
		else
		{
			if (check_array_mediane(r->a, mediane, 0) == 1)
			{
				ra(r->a);
				pushed_down++;
			}
			dest->max->size++;
		}
	}
	rotate_mini_chunks(r, dest, pushed_down);
}
