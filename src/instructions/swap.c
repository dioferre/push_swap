/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:00:23 by dioferre          #+#    #+#             */
/*   Updated: 2024/09/14 17:32:03 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *stack_a)
{
	swap_nodes(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b)
{
	swap_nodes(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	ft_putstr_fd("ss\n", 1);
}
