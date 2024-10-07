/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   015_multiple_args_parsing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:31:24 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/07 11:46:29 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_atoi(char *str)
{
	int	i;
	int	neg_check;

	i = 0;
	neg_check = 0;
	while (str[i] != '\0')
	{
		if ((is_num(str[i]) == 1)
			|| ((str[i] == '-') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
		{
			if (str[i] == '-')
				neg_check++;
		}
		else
			return (-1);
		if (neg_check > 1)
			return (-1);
		i++;
	}
	return (0);
}

static int	ps_atoi2(t_root *r, char *str, int *arr)
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
	if (result > INT_MAX || result <= -2147483647)
		return (free(arr), handle_errors(r), -1);
	return ((int)(result *= neg_check));
}

int	*handle_argvs(t_root *r, int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = malloc((argc - 1) * sizeof(int));
	i = 1;
	while (argv[i])
	{
		if (check_atoi(argv[i]) == 0)
			arr[i - 1] = ps_atoi2(r, argv[i], arr);
		else
		{
			free(arr);
			handle_errors(r);
		}
		i++;
	}
	if (check_double_nrs(arr, i - 1) == 1)
	{
		free(arr);
		handle_errors(r);
	}
	r->arg_len = i - 1;
	return (arr);
}
