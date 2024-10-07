/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   140_sort6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:28:25 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/06 14:21:50 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_med_sort6(t_stack *a, int size, int mediane)
{
	int	*sorted_arr;
	int	i;

	i = 0;
	sorted_arr = org_array(a->array, size, 0);
	while (i < size)
	{
		if (a->array[i] <= mediane)
		{
			free(sorted_arr);
			return (1);
		}
		i++;
	}
	free(sorted_arr);
	return (0);
}

int	mini_is_sorted(int *array, int size)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = org_array(array, size, 0);
	while (i < size)
	{
		if (array[i] != tmp[i])
			return (free(tmp), -1);
		i++;
	}
	free(tmp);
	return (1);
}

static int	check_sort6(t_stack *a, t_stack *b, int size)
{
	if (size <= 1)
		return (1);
	else if (size == 2)
	{
		if (a->array[0] > a->array[1])
			sa(a);
		return (1);
	}
	else if (size == 3)
	{
		sort3(a, b, 'a');
		return (1);
	}
	else if (mini_is_sorted(a->array, size) == 1)
		return (1);
	else
		return (0);
}

void	sort6_p2(t_stack *a, t_stack *b, int pushed_away, int pushed_down)
{
	while (pushed_down > 0)
	{
		rra(a);
		pushed_down--;
	}
	double_sort3(a, b);
	while (pushed_away > 0)
	{
		pa(a, b);
		pushed_away--;
	}
}

void	sort6(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	mediane;
	int	pushed_down;
	int	pushed_away;

	i = -1;
	pushed_down = 0;
	pushed_away = 0;
	if (check_sort6(a, b, size) == 1)
		return ;
	mediane = get_mediane(a, size, 0);
	while (++i < size && check_med_sort6(a, size, mediane) == 1)
	{
		if (a->array[0] > mediane)
		{
			ra(a);
			pushed_down++;
		}
		else
		{
			pb(a, b);
			pushed_away++;
		}
	}
	sort6_p2(a, b, pushed_away, pushed_down);
}
