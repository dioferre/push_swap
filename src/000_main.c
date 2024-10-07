/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:33:53 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/05 17:14:02 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_allocation(t_root *r, void *var)
{
	if (!var)
		handle_errors(r);
}

void	root_init(t_root *r)
{
	r->a = (t_stack *)malloc(sizeof(t_stack));
	check_allocation(r, r->a);
	r->b = (t_stack *)malloc(sizeof(t_stack));
	check_allocation(r, r->b);
	r->sorted_list = (t_stack *)malloc(sizeof(t_stack));
	check_allocation(r, r->sorted_list);
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

int	main(int argc, char **argv)
{
	t_root	*r;

	r = (t_root *)malloc(sizeof(t_root));
	root_init(r);
	if (argc == 1)
		handle_argc1(r);
	if (!r)
		handle_errors(r);
	if (argc == 2)
		r->a->array = handle_parsing(r, argv[1]);
	else
		r->a->array = handle_argvs(r, argc, argv);
	r->a->len = r->arg_len;
	r->b->array = malloc(r->arg_len * sizeof(int));
	r->sorted_list->len = r->arg_len;
	r->sorted_list->array = org_array(r->a->array, r->arg_len, 0);
	sort(r);
	kill_root(r);
	return (1);
}
