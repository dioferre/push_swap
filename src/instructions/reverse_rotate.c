/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:04:13 by dioferre          #+#    #+#             */
/*   Updated: 2024/09/14 17:36:20 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *stack_a)
{
	reverse_rotate_nodes(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate_nodes(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_nodes(stack_a);
	reverse_rotate_nodes(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
