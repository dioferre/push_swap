/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:35:24 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/25 15:11:39 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*populate_str(char const *s, int start, int end);
static int	count_words(char const *s, char c);
static char	**ft_free(char **arr, int j);

char	**ft_split(char const *s, char c)

{
	char	**arr;

	auto int i = 0, j = 0, index = -1, nr_words;
	nr_words = count_words(s, c);
	arr = (char **)malloc((nr_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (j < nr_words)
	{
		if (s[i] != c && index < 0)
			index = i;
		if ((s[i] == c || i == (int)ft_strlen(s)) && index >= 0)
		{
			arr[j] = populate_str(s, index, i);
			if (arr[j] == NULL)
				return (ft_free(arr, j));
			j++;
			index = -1;
		}
		i++;
	}
	arr[nr_words] = NULL;
	return (arr);
}

static char	*populate_str(char const *s, int start, int end)

{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while ((i + start) < end)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}

static int	count_words(char const *s, char c)

{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_free(char **arr, int j)

{
	int	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
/*
int main(int argc, char **argv)

{
	char c;

	c = argv[2][0];
	printf("%s\n", ft_split(argv[1], c));
	return (0);
}
*/
