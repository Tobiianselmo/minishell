/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:15:48 by tanselmo          #+#    #+#             */
/*   Updated: 2024/03/11 12:31:41 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	a;

	needle_len = ft_strlen(needle);
	i = 0;
	a = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	while (haystack[i] != '\0' && i < len)
	{
		a = 0;
		while (haystack[i + a] == needle[a] && haystack[i + a] != '\0'
			&& i + a < len)
			a++;
		if (needle[a] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/* int	main()
{
	const char	*haystack;
	const char	*needle;

	haystack = "Hola como estas?";
	needle = "como";
	printf("%s\n", ft_strnstr(haystack, needle, 10));
	return (0);
} */
