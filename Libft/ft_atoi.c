/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:30:45 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/22 16:14:05 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *nptr)

{
	auto int count = 0, sign = 0, result = 0, ncheck = 1;
	while (ft_isspace(nptr[count]))
		count++;
	while (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			ncheck++;
		sign++;
		count++;
	}
	if (sign > 1)
		return (0);
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		result *= 10;
		result += nptr[count] - '0';
		count++;
	}
	if (ncheck != 1)
		result = -result;
	return (result);
}

static int	ft_isspace(int c)

{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}
/*
int	main(int argc, char**argv)

{
	printf("Input: %s\n\n", argv[1]);
	printf("Original: %d\n", atoi(argv[1]));
	printf("FT: %d\n", ft_atoi(argv[1]));
	return (0);
}*/
