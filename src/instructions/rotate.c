/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:04:06 by dioferre          #+#    #+#             */
/*   Updated: 2024/09/14 17:36:16 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *stack_a)
{
	rotate_nodes(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack_b)
{
	rotate_nodes(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	ft_putstr_fd("rr\n", 1);
}
