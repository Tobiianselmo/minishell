/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaup_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:30:50 by tanselmo          #+#    #+#             */
/*   Updated: 2024/02/27 12:24:14 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexaup_pf(unsigned int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (n < 16)
		return (ft_putchar_pf(base[n]));
	if (n >= 16)
	{
		i += ft_hexaup_pf(n / 16);
		i += ft_hexaup_pf(n % 16);
	}
	return (i);
}
