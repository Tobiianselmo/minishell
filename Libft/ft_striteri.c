/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:40:53 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/22 13:16:56 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		while (a < i)
		{
			f(a, s);
			s++;
			a++;
		}
	}
}
