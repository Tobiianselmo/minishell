/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexapointer_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:31:13 by tanselmo          #+#    #+#             */
/*   Updated: 2024/02/27 12:24:37 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexalong(unsigned long n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n < 16)
	{
		return (ft_putchar_pf(base[n]));
	}
	if (n >= 16)
	{
		i += ft_hexalong(n / 16);
		i += ft_hexalong(n % 16);
	}
	return (i);
}

int	ft_hexapointer_pf(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
	{
		write(1, "0x", 2);
		i += ft_hexalong(n);
		return (i + 2);
	}
}
