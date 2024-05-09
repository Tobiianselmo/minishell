/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:50:14 by tanselmo          #+#    #+#             */
/*   Updated: 2024/02/27 12:23:36 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_numbers(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_u_pf(unsigned int n)
{
	int	count;

	count = count_numbers(n);
	if (n >= 10)
		ft_putnbr_u_pf(n / 10);
	ft_putchar_pf((n % 10) + '0');
	return (count);
}
