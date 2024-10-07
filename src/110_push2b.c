/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   110_push2b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:53:45 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 12:22:29 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Mediane 1 is the smallest half
// Mediane 2 is the smallest quarter

void	fix_chunk_size(t_stack *a, t_stack *b, t_data *data)
{
	int	pushed_down;

	pushed_down = data->half1->size;
	if (a->checkpoint >= 3)
	{
		data->half2->size = data->half2->size - data->half1->size;
		while (pushed_down > 0)
		{
			rrb(b);
			pushed_down--;
		}
	}
	else
		data->half1->size = data->half1->size - data->half2->size;
}

void	push2b_case2(t_stack *a, t_stack *b, t_data *data)
{
	int	mediane;
	int	mediane2;

	mediane = get_mediane(a, a->len, 0);
	mediane2 = get_mediane(a, a->len, 2);
	while (check_array_mediane(a, mediane, 0) == 1 && a->len > 3)
	{
		if (a->array[0] < mediane)
		{
			pb(a, b);
			data->half1->size++;
			if (b->array[0] < mediane2)
			{
				if (a->array[0] >= mediane)
					rr(a, b);
				else
					rb(b);
				data->half2->size++;
			}
		}
		else
			ra(a);
	}
	fix_chunk_size(a, b, data);
}

void	push2b_case1(t_stack *a, t_stack *b, t_data *data)
{
	int	mediane;
	int	mediane2;

	mediane = get_mediane(a, a->len, 0);
	mediane2 = get_mediane(a, a->len, 2);
	while (check_array_mediane(a, mediane, 0) == 1 && a->len > 3)
	{
		if (a->array[0] < mediane)
		{
			pb(a, b);
			data->half2->size++;
			if (b->array[0] > mediane2 && a->checkpoint >= 3)
			{
				if (a->array[0] >= mediane)
					rr(a, b);
				else
					rb(b);
				data->half1->size++;
			}
		}
		else
			ra(a);
	}
	fix_chunk_size(a, b, data);
}

void	push2b(t_stack *a, t_stack *b, t_data *data)
{
	if (a->checkpoint < 3)
		push2b_case2(a, b, data);
	else
		push2b_case1(a, b, data);
}
