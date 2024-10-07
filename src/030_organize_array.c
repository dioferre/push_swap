/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   030_organize_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:43:21 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 14:40:37 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	cpy_array(int *src, int *dest, int src_size)
{
	int	i;

	i = 0;
	while (i < src_size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	partition(int *arr, int start, int end)
{
	int	p;
	int	i;
	int	j;

	p = arr[start];
	i = start;
	j = end;
	while (i < j)
	{
		while (arr[i] <= p && i < end)
			i++;
		while (arr[j] > p && j > start)
			j--;
		if (i < j)
			qs_swap(&arr[i], &arr[j]);
	}
	qs_swap(&arr[start], &arr[j]);
	return (j);
}

void	org_quicksort(int *arr, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(arr, start, end);
		org_quicksort(arr, start, pivot - 1);
		org_quicksort(arr, pivot + 1, end);
	}
}

void	reverse_array(int *arr, int len)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = malloc(len * sizeof(int));
	cpy_array(arr, tmp, len);
	len -= 1;
	while (i <= len)
	{
		arr[i] = tmp[len - i];
		i++;
	}
	free(tmp);
}

int	*org_array(int *arr, int len, int flag)
{
	int	*sorted_arr;

	sorted_arr = malloc(len * sizeof(int));
	cpy_array(arr, sorted_arr, len);
	org_quicksort(sorted_arr, 0, len - 1);
	if (flag == 1)
		reverse_array(sorted_arr, len);
	return (sorted_arr);
}
