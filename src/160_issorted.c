/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   160_issorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:46:36 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 18:13:48 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_stack *s, t_stack *sl)
{
	int	i;
	int	j;

	i = s->len - 1;
	j = sl->len - 1;
	while (i > 0 && j > 0)
	{
		if (s->array[i] != sl->array[j])
			return (-1);
		i--;
		j--;
	}
	return (1);
}

int	array_cmp(t_stack *s, t_stack *sorted_arr)
{
	int	i;

	i = 0;
	if (s->len != sorted_arr->len)
		return (-1);
	while (i < sorted_arr->len)
	{
		if (s->array[i] != sorted_arr->array[i])
			return (-1);
		i++;
	}
	return (1);
}

// flag 1 for more than mediane      flag 0 for less than mediane
int	check_array_mediane(t_stack *s, int mediane, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (i < s->len)
		{
			if (s->array[i] < mediane)
				return (1);
			i++;
		}
		return (-1);
	}
	else
	{
		while (i < s->len)
		{
			if (s->array[i] > mediane)
				return (1);
			i++;
		}
		return (-1);
	}
}
