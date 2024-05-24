/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:49:16 by tanselmo          #+#    #+#             */
/*   Updated: 2024/02/27 15:11:24 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str != '\0' && *str != c)
			{
				str++;
			}
		}
		else
		{
			str++;
		}
	}
	return (count);
}

static int	check_matrix(char **matrix, int j)
{
	if (!matrix[j])
	{
		while (j >= 0)
			free(matrix[j--]);
		free(matrix);
		return (0);
	}
	return (1);
}

static char	**str_to_matrix(char **matrix, char const *s, char c, int start)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == len) && start != -1)
		{
			matrix[j] = ft_substr(s, start, (i - start));
			if (!check_matrix(matrix, j))
				return (NULL);
			j++;
			start = -1;
		}
		i++;
	}
	matrix[j] = 0;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		start;

	start = -1;
	matrix = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!matrix)
		return (0);
	return (str_to_matrix(matrix, s, c, start));
}
