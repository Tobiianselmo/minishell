/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:12:00 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/09 13:40:07 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char		*start;
	const char		*end;
	char			*trim;
	size_t			i;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && is_set(*start, set))
		start++;
	while (end > start && is_set(*end, set))
		end--;
	trim = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!trim)
		return (NULL);
	i = 0;
	while (start <= end)
		trim[i++] = *start++;
	trim[i] = '\0';
	return (trim);
}

/* int	main()
{
	char const *s1 = "bbbbbbhola como estasbbbbbbb";
	char const *set = "b";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
} */
