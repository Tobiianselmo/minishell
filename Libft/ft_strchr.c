/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:16:05 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/04 15:40:56 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ('\0' == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/* int	main()
{
	char	*s;
	int	c;

	s = "";
	c = 'z';
	printf("%s\n", ft_strchr(s, c));
	return (0);
} */
