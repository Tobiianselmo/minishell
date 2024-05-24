/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:16:17 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/05 15:47:37 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while (n-- != '\0')
	{
		while (*a1 != *a2)
		{
			return (*a1 - *a2);
		}
		a1++;
		a2++;
	}
	return (0);
}

/* int	main()
{
	char	*s1;
    char	*s2;

    s1 = "abc";
    s2 = "abc";
    printf("%d\n", ft_memcmp(s1, s2, 7));
    return (0);
} */