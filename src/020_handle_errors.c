/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   020_handle_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:15:54 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/07 11:20:46 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	kill_parsing(t_root *r, char **split_array, int *nr_array)
{
	free_split(split_array);
	free(nr_array);
	handle_errors(r);
}

void	kill_root(t_root *r)
{
	free(r->a->array);
	free(r->b->array);
	free(r->sorted_list->array);
	free(r->a);
	free(r->b);
	free(r->sorted_list);
	free(r);
}

void	handle_errors(t_root *r)
{
	ft_putstr_fd("Error\n", 2);
	free(r->a);
	free(r->b);
	free(r->sorted_list);
	free(r);
	exit(-1);
}

void	handle_errors2(t_root *r)
{
	kill_root(r);
	exit(-1);
}

void	handle_argc1(t_root *r)
{
	free(r->a);
	free(r->b);
	free(r->sorted_list);
	free(r);
	exit(-1);
}
