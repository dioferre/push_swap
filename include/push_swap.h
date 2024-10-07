/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:19:34 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/07 11:47:06 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//   LIMIT DEFINES
# define INT_MAX 2147483647

//   ERROR DEFINES

# define NO_NR_ERROR -8
# define NO_ARG_ERROR -9
# define MALLOC_ERROR -10

//   INCLUDES
# include "../Libft/libft.h"
# include <stdio.h>

//   STRUCTS

typedef struct s_chunk
{
	int	size;
}					t_chunk;

typedef struct s_split_chunk
{
	t_chunk	*min;
	t_chunk	*med;
	t_chunk	*max;
}					t_split_chunk;

typedef struct s_data
{
	t_chunk	*half1;
	t_chunk	*half2;
}					t_data;

typedef struct s_stack
{
	int	*array;
	int	mediane;
	int	len;
	int	checkpoint;
	int	moves;
	int	pushed_down;
}						t_stack;

typedef struct s_root
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*sorted_list;
	int		arg_len;
}						t_root;

//   FUNCTIONS

// SORT FUNCTIONS
void	quicksort(t_root *r);
void	sort(t_root *r);
int		get_mediane(t_stack *s, int len, int flag);
void	organize_b(t_root *r, t_chunk *chunk);
int		sort_a(t_root *root, t_chunk *chunk);
int		sort_b(t_root *root, t_chunk *chunk);
void	push2b(t_stack *a, t_stack *b, t_data *data);
void	push_mini_chunks_a(t_root *r, t_chunk *chunk, t_split_chunk *dest);
void	push_mini_chunks_b(t_root *r, t_chunk *chunk, t_split_chunk *dest);
void	rotate_mc_back(t_root *r, int nr_elems);
void	rotate_b_chunks(t_root *r, t_split_chunk *dest);
void	double_sort3(t_stack *a, t_stack *b);

// SMALL SORTING FUNCTIONS
void	sort3(t_stack *a, t_stack *b, char stack);
void	sort5(t_stack *a, t_stack *b);
void	double_sort3(t_stack *a, t_stack *b);
void	sort6(t_stack *a, t_stack *b, int size);

// UTIL FUNCTIONS
void	root_init(t_root *r);
void	qs_swap(int *a, int *b);
int		check_array_mediane(t_stack *s, int mediane, int flag);
int		check_sorted(t_stack *s, t_stack *sl);
int		array_cmp(t_stack *s, t_stack *sorted_arr);
int		*org_array(int *arr, int len, int flag);

// ERROR FUNCTIONS
void	kill_parsing(t_root *r, char **split_array, int *nr_array);
void	check_allocation(t_root *r, void *var);
void	kill_root(t_root *r);
void	handle_errors(t_root *r);
void	handle_errors2(t_root *r);
void	handle_argc1(t_root *r);

// PARSING FUNCTIONS
void	free_split(char **split_array);
int		is_num(char c);
int		check_double_nrs(int *nr_array, int len);
int		*handle_parsing(t_root *r, char *arg);
int		*handle_argvs(t_root *r, int argc, char **argv);

//    INSTRUCTION FUNCTIONS

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//    INSTRUCTION UTIL FUNCTIONS

int		push_from_to(t_stack *src, t_stack *dest);
int		reverse_rotate_nodes(t_stack *stack);
int		rotate_nodes(t_stack *stack);
int		swap_nodes(t_stack *stack);

//    BONUS FUNCTIONS
void	execute_cmds(t_root *r, char *cmd);

#endif
