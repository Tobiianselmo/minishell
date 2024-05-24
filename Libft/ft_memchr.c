/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:16:20 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/07 12:58:46 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (*str == ch)
		{
			return (str);
		}
		i++;
		str++;
	}
	return (NULL);
}

/* int	main()
{
	char	*s;
	int	c;

	s = "Hola buen dia!";
	c = 'b';
	printf("%s\n", ft_memchr(s, c, 5));
	return (0);
} */