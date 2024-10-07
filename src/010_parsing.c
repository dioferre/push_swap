/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:43:22 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/07 11:38:15 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	free_split(char **split_array)
{
	int	i;

	i = 0;
	while (split_array[i])
	{
		free (split_array[i]);
		i++;
	}
	free (split_array);
}

int	ps_atoi(t_root *r, char *str, char **split_array, int *nr_array)
{
	long	result;
	int		neg_check;
	int		i;

	neg_check = 1;
	result = 0;
	i = 0;
	if (str[i] == '-')
	{
		neg_check = -1;
		i++;
	}
	while (is_num(str[i]))
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	if ((!is_num(str[i]) && (str[i] != '\0' && str[i] != ' '))
		|| (neg_check == -1 && ft_strlen(str) <= 1)
		|| (result > INT_MAX || result <= -2147483647))
		kill_parsing(r, split_array, nr_array);
	return ((int)(result *= neg_check));
}

int	check_double_nrs(int *nr_array, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < len)
	{
		while (j < len)
		{
			if (nr_array[i] == nr_array[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	*handle_parsing(t_root *r, char *arg)
{
	char	**split_array;
	int		*nr_array;
	int		len;
	int		i;

	len = 0;
	i = -1;
	split_array = ft_split(arg, ' ');
	while (split_array[len])
		len++;
	nr_array = malloc(len * sizeof(int));
	while (++i != len)
		nr_array[i] = ps_atoi(r, split_array[i], split_array, nr_array);
	if (len <= 1)
	{
		free(nr_array);
		free_split(split_array);
		handle_argc1(r);
	}
	if (check_double_nrs(nr_array, len))
		kill_parsing(r, split_array, nr_array);
	r->arg_len = len;
	return (free_split(split_array), nr_array);
}
