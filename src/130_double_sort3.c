/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   130_double_sort3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:47:20 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 16:40:51 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	double_sort3_utils_p2(t_stack *a, t_stack *b, char flag)
{
	if (flag == 'a')
	{
		ra(a);
		sa(a);
		rra(a);
		if (a->array[0] > a->array[1])
			sa(a);
	}
	else if (flag == 'b')
	{
		rb(b);
		sb(b);
		rrb(b);
		if (b->array[0] < b->array[1])
			sb(b);
	}
}

static void	double_sort3_utils(t_stack *a, t_stack *b)
{
	rr(a, b);
	ss(a, b);
	rrr(a, b);
	if (a->array[0] > a->array[1] || b->array[0] < b->array[1])
	{
		if (a->array[0] > a->array[1] && b->array[0] < b->array[1])
			ss(a, b);
		else if (a->array[0] > a->array[1])
			sa(a);
		else
			sb(b);
	}
}

void	double_sort3(t_stack *a, t_stack *b)
{
	if (a->array[0] > a->array[1] || b->array[0] < b->array[1])
	{
		if (a->array[0] > a->array[1] && b->array[0] < b->array[1])
			ss(a, b);
		else if (a->array[0] > a->array[1])
			sa(a);
		else
			sb(b);
	}
	if ((a->array[0] > a->array[1] || a->array[1] > a->array[2])
		|| (b->array[0] < b->array[1] || b->array[1] < b->array[2]))
	{
		if ((a->array[0] > a->array[1] || a->array[1] > a->array[2])
			&& (b->array[0] < b->array[1] || b->array[1] < b->array[2]))
			double_sort3_utils(a, b);
		else if (a->array[0] > a->array[1] || a->array[1] > a->array[2])
			double_sort3_utils_p2(a, b, 'a');
		else
			double_sort3_utils_p2(a, b, 'b');
	}
}
