/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:16:08 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/04 13:04:09 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	p = b;
	while (i < len)
	{
		p[i] = (char)c;
		i++;
	}
	return (b);
}

/* int	main()
{
	char	s[20] = "";
	int	c = '0';

	printf("%p\n", ft_memset(s, c, 6));
	printf("%s\n", s);
	return (0);
} */
