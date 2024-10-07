/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:17:45 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/04 12:47:41 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_split_chunk	*create_dest(void)
{
	t_split_chunk	*dest;

	dest = malloc(sizeof(t_split_chunk));
	dest->max = malloc(sizeof(t_chunk));
	dest->med = malloc(sizeof(t_chunk));
	dest->min = malloc(sizeof(t_chunk));
	dest->max->size = 0;
	dest->med->size = 0;
	dest->min->size = 0;
	return (dest);
}

void	destroy_dest(t_split_chunk *dest)
{
	free(dest->max);
	free(dest->med);
	free(dest->min);
	free(dest);
}

int	sort_b(t_root *root, t_chunk *chunk)
{
	t_split_chunk	*dest;

	dest = create_dest();
	if (chunk->size > 6)
	{
		push_mini_chunks_b(root, chunk, dest);
		sort_a(root, dest->max);
		rotate_b_chunks(root, dest);
		sort_a(root, dest->med);
		organize_b(root, dest->min);
		sort_a(root, dest->min);
	}
	else
	{
		organize_b(root, chunk);
		sort6(root->a, root->b, chunk->size);
	}
	destroy_dest(dest);
	return (1);
}

int	sort_a(t_root *root, t_chunk *chunk)
{
	t_split_chunk	*dest;

	dest = create_dest();
	if (chunk->size > 6)
	{
		push_mini_chunks_a(root, chunk, dest);
		sort_a(root, dest->max);
		rotate_mc_back(root, dest->med->size);
		sort_a(root, dest->med);
		rotate_mc_back(root, dest->min->size);
		sort_a(root, dest->min);
	}
	sort6(root->a, root->b, chunk->size);
	destroy_dest(dest);
	return (1);
}
