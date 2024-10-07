/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   140_get_mediane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:41:00 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 12:48:02 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	calculate_mediane(t_stack *s, int len, char flag)
{
	int	*sorted_arr;
	int	mediane;

	if (flag == 'a')
	{
		sorted_arr = org_array(s->array, len, 0);
		len -= 1;
		mediane = sorted_arr[(len / 2)];
		free (sorted_arr);
	}
	else
	{
		sorted_arr = org_array(s->array, len, 1);
		len -= 1;
		mediane = sorted_arr[(len / 2)];
		free (sorted_arr);
	}
	return (mediane);
}

static int	get_double_mediane(t_stack *s, int len, char flag)
{
	int	*sorted_arr;
	int	mediane;

	if (flag == 'a')
	{
		sorted_arr = org_array(s->array, len, 0);
		mediane = sorted_arr[(len / 4)];
		free (sorted_arr);
	}
	else
	{
		sorted_arr = org_array(s->array, len, 1);
		mediane = sorted_arr[(len / 4) * 3];
		free (sorted_arr);
	}
	return (mediane);
}

// 0 Mediane A
// 1 Mediane B
// 2 Mediane mediane A
// 3 Mediane mediane B

int	get_mediane(t_stack *s, int len, int flag)
{
	if (flag == 0)
		return (calculate_mediane(s, len, 'a'));
	else if (flag == 1)
		return (calculate_mediane(s, len, 'b'));
	else if (flag == 2)
		return (get_double_mediane(s, len, 'a'));
	else if (flag == 3)
		return (get_double_mediane(s, len, 'b'));
	else
		return (0);
}
