/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:15:03 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/06 14:38:16 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	organize_b(t_root *r, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->size)
	{
		pa(r->a, r->b);
		i++;
	}
	if (chunk->size <= 3)
	{
		while (i < chunk->size)
		{
			pa(r->a, r->b);
			i++;
		}
	}
}

void	kill_data(t_data *data)
{
	free(data->half1);
	free(data->half2);
	free(data);
}

void	quicksort(t_root *r)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->half1 = malloc(sizeof(t_chunk));
	data->half2 = malloc(sizeof(t_chunk));
	data->half1->size = 0;
	data->half2->size = 0;
	if (array_cmp(r->a, r->sorted_list) == -1 && r->a->len > 3)
	{
		push2b(r->a, r->b, data);
		r->a->checkpoint = 3;
		quicksort(r);
	}
	else if (r->a->len == 3)
	{
		sort3(r->a, r->b, 'f');
		r->a->checkpoint = 3;
		kill_data(data);
		return ;
	}
	sort_b(r, data->half1);
	sort_b(r, data->half2);
	kill_data(data);
	return ;
}

void	handle_small_sorts(t_root *r)
{
	if (r->arg_len == 2)
		sa(r->a);
	else if (r->arg_len == 3)
		sort3(r->a, r->b, 'f');
	else if (r->arg_len == 4 || r->arg_len == 5)
		sort5(r->a, r->b);
	else if (r->arg_len == 6)
		sort6(r->a, r->b, r->arg_len);
}

void	sort(t_root *r)
{
	if (check_sorted(r->a, r->sorted_list) == 1)
		handle_errors2(r);
	if (r->arg_len <= 6)
		return (handle_small_sorts(r));
	r->a->checkpoint = 0;
	r->sorted_list->len = r->arg_len;
	quicksort(r);
}
