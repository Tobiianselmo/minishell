/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:15:44 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/04 17:21:07 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != (char)c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/* int	main()
{
	char	*s;
	int	c;

	s = "\0";
	c = '\0';
	printf("%s\n", ft_strrchr(s, c));
	return (0);
} */
