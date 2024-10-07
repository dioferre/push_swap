/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:49:23 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/06 15:06:11 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	execute_double_cmds(t_root *r, char *cmd)
{
	if (!ft_strncmp(cmd, "ss\n", 3))
	{
		swap_nodes(r->a);
		swap_nodes(r->b);
	}
	else if (!ft_strncmp(cmd, "rr\n", 3))
	{
		rotate_nodes(r->a);
		rotate_nodes(r->b);
	}
	else if (!ft_strncmp(cmd, "rrr\n", 4))
	{
		reverse_rotate_nodes(r->a);
		reverse_rotate_nodes(r->b);
	}
}

void	clean_kill(t_root *r, char *cmd)
{
	ft_putstr_fd("Error\n", 1);
	free(cmd);
	kill_root(r);
	exit (-1);
}

void	execute_cmds(t_root *r, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
		push_from_to(r->b, r->a);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		push_from_to(r->a, r->b);
	else if (!(ft_strncmp(cmd, "sa\n", 3)))
		swap_nodes(r->a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		swap_nodes(r->b);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		rotate_nodes(r->a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rotate_nodes(r->b);
	else if (!ft_strncmp(cmd, "rra\n", 3))
		reverse_rotate_nodes(r->a);
	else if (!ft_strncmp(cmd, "rrb\n", 3))
		reverse_rotate_nodes(r->b);
	else if (!ft_strncmp(cmd, "ss\n", 3)
		|| (!ft_strncmp(cmd, "rr\n", 3) || !ft_strncmp(cmd, "rrr\n", 4)))
		execute_double_cmds(r, cmd);
	else
		clean_kill(r, cmd);
}
