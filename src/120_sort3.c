/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   120_sort3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:04:07 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/06 14:39:47 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort3a(t_stack *a)
{
	if (a->array[0] > a->array[1] || a->array[1] > a->array[2])
	{
		if (a->array[0] > a->array[1])
			sa(a);
		if (a->array[0] > a->array[1] || a->array[1] > a->array[2])
		{
			ra(a);
			sa(a);
			rra(a);
			if (a->array[0] > a->array[1])
				sa(a);
		}
	}
}

static void	sort3b(t_stack *b)
{
	if (b->array[0] < b->array[1] || b->array[1] < b->array[2])
	{
		if (b->array[0] < b->array[1])
			sb(b);
		if (b->array[0] < b->array[1] || b->array[1] < b->array[2])
		{
			rb(b);
			sb(b);
			rrb(b);
			if (b->array[0] < b->array[1])
				sb(b);
		}
	}
}

static void	sort3f(t_stack *a)
{
	if (a->array[0] < a->array[1] && a->array[1] < a->array[2])
		return ;
	if (a->array[0] > a->array[1]
		&& a->array[2] > a->array[1] && a->array[2] > a->array[0])
		sa(a);
	else if (a->array[0] > a->array[1]
		&& a->array[2] > a->array[1] && a->array[0] > a->array[2])
		ra(a);
	else if (a->array[1] > a->array[0]
		&& a->array[1] > a->array[2] && a->array[0] > a->array[2])
		rra(a);
	else if (a->array[1] > a->array[0]
		&& a->array[1] > a->array[2] && a->array[2] > a->array[0])
	{
		sa(a);
		ra(a);
	}
	else if (a->array[0] > a->array[1]
		&& a->array[1] > a->array[2] && a->array[0] > a->array[2])
	{
		sa(a);
		rra(a);
	}
}

void	sort3(t_stack *a, t_stack *b, char stack)
{
	if (stack == 'a')
		sort3a(a);
	else if (stack == 'b')
		sort3b(b);
	else
		sort3f(a);
}
