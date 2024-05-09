/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:16:15 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/18 17:08:34 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (!cdst && !csrc)
		return (dst);
	while (n--)
	{
		*cdst++ = *csrc++;
	}
	return (dst);
}

/* int	main()
{
	char	s1[] = "";
    char	s2[] = "";
    printf("%s\n", s1);
    ft_memcpy(s1, s2, 4);
    printf("%s\n", s1);
    return (0);
} */