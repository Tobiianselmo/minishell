/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:16:00 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/11 16:56:25 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	a;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = ft_strlen(dst);
	a = 0;
	if (dstsize <= dst_len)
	{
		return (dstsize + src_len);
	}
	while ((src[a] != '\0') && (i + 1 < dstsize))
	{
		dst[i] = src[a];
		i++;
		a++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

/* int	main()
{
	char	dst[] = "Holaaa";
	char	src[] = "bien";
	
	printf("%zu\n", ft_strlcat(dst, src, 6));
	return (0);
} */
