/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:15:52 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/04 16:15:51 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i != n))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
		}
		else if ((unsigned char)s2[i] > (unsigned char)s1[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

/* int	main()
{
	const char	*s1;
	const char	*s2;
	
	s1 = "\107";
	s2 = "\0";
	printf("%d", ft_strncmp(s1, s2, 5));
	return (0);	
} */
