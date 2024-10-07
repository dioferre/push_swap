/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   125_sort5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:27:38 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/07 11:40:01 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_smallest(t_stack *a)
{
	int	i;
	int	smallest_index;

	i = 1;
	smallest_index = 0;
	while (i < a->len)
	{
		if (a->array[smallest_index] > a->array[i])
			smallest_index = i;
		i++;
	}
	return (a->array[smallest_index]);
}

void	sort4(t_stack *a, t_stack *b)
{
	int	mediane;

	mediane = get_mediane(a, a->len, 2);
	if (a->array[3] < mediane)
	{
		rra(a);
		pb(a, b);
		sort3(a, b, 'f');
		pa(a, b);
	}
	else
	{
		while (a->array[0] >= mediane)
			ra(a);
		pb(a, b);
		sort3(a, b, 'f');
		pa(a, b);
	}
}

void	sort5(t_stack *a, t_stack *b)
{
	int	smallest;

	if (a->len == 4)
		return (sort4(a, b));
	smallest = find_smallest(a);
	if (a->array[4] == smallest || a->array[3] == smallest)
	{
		while (a->array[0] != smallest)
			rra(a);
		pb(a, b);
	}
	else
	{
		while (a->array[0] != smallest)
			ra(a);
		pb(a, b);
	}
	sort4(a, b);
	pa(a, b);
}
