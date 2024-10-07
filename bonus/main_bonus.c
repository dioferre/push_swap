/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:27:55 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/05 18:48:22 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_allocation_bns(t_root *r, void *var)
{
	if (!var)
		handle_errors(r);
}

static void	root_init_bonus(t_root *r)
{
	r->a = (t_stack *)malloc(sizeof(t_stack));
	check_allocation_bns(r, r->a);
	r->b = (t_stack *)malloc(sizeof(t_stack));
	check_allocation_bns(r, r->b);
	r->sorted_list = (t_stack *)malloc(sizeof(t_stack));
	check_allocation_bns(r, r->sorted_list);
	r->a->mediane = 0;
	r->a->len = 0;
	r->a->checkpoint = 0;
	r->a->moves = 0;
	r->a->pushed_down = 0;
	r->b->mediane = 0;
	r->b->len = 0;
	r->b->checkpoint = 0;
	r->b->moves = 0;
	r->b->pushed_down = 0;
	r->arg_len = 0;
}

int	check_checker(t_root *r)
{
	int	i;

	i = 0;
	if (r->b->len > 0 || r->sorted_list->len != r->a->len)
		return (0);
	while (i < r->arg_len)
	{
		if (r->sorted_list->array[i] != r->a->array[i])
			return (0);
		i++;
	}
	return (1);
}

void	handle_cmds(t_root *r)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_cmds(r, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_root	*r;

	r = (t_root *)malloc(sizeof(t_root));
	root_init_bonus(r);
	if (argc == 1)
		handle_argc1(r);
	else if (argc == 2)
		r->a->array = handle_parsing(r, argv[1]);
	else
		r->a->array = handle_argvs(r, argc, argv);
	r->b->array = malloc(r->arg_len * sizeof(int));
	r->sorted_list->len = r->arg_len;
	r->a->len = r->arg_len;
	r->sorted_list->array = org_array(r->a->array, r->a->len, 0);
	handle_cmds(r);
	if (check_checker(r) == 0)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	kill_root(r);
}
