/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:12:48 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 14:39:16 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_from_to(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_from_to(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
