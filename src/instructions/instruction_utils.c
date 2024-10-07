/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:10:55 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 11:43:25 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	swap_nodes(t_stack *stack)
{
	int	temp;

	stack->moves++;
	if (stack->len < 2)
		return (-1);
	temp = stack->array[1];
	stack->array[1] = stack->array[0];
	stack->array[0] = temp;
	return (1);
}

int	rotate_nodes(t_stack *stack)
{
	int	temp;
	int	i;

	stack->moves++;
	if (stack->len < 2)
		return (-1);
	i = 0;
	temp = stack->array[0];
	while (i < stack->len - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->len - 1] = temp;
	return (1);
}

int	reverse_rotate_nodes(t_stack *stack)
{
	int	temp;
	int	i;

	stack->moves++;
	if (stack->len < 2)
		return (-1);
	i = stack->len - 1;
	temp = stack->array[stack->len - 1];
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = temp;
	return (1);
}

int	push_from_to(t_stack *src, t_stack *dest)
{
	int	i;

	if (src->len < 1)
		return (-1);
	src->len--;
	src->moves++;
	dest->len++;
	i = dest->len - 1;
	while (i > 0)
	{
		dest->array[i] = dest->array[i - 1];
		i--;
	}
	dest->array[0] = src->array[0];
	while (i < src->len)
	{
		src->array[i] = src->array[i + 1];
		i++;
	}
	return (0);
}
