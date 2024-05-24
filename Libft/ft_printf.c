/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:19:19 by tanselmo          #+#    #+#             */
/*   Updated: 2024/02/27 12:23:56 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_conversion(char const *input, va_list element)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_putchar_pf(va_arg(element, int));
	else if (*input == 's')
		i += ft_putstr_pf(va_arg(element, char *));
	else if (*input == 'p')
		i += ft_hexapointer_pf((unsigned long)va_arg(element, void *));
	else if (*input == 'd' || *input == 'i')
		i += ft_putnbr_pf(va_arg(element, int));
	else if (*input == 'u')
		i += ft_putnbr_u_pf(va_arg(element, unsigned int));
	else if (*input == 'x')
		i += ft_hexa_pf(va_arg(element, int));
	else if (*input == 'X')
		i += ft_hexaup_pf(va_arg(element, int));
	else if (*input == '%')
		i += write(1, "%%", 1);
	return (i);
}

int	ft_printf(char const *input, ...)
{
	int		i;
	va_list	element;

	i = 0;
	va_start(element, input);
	if (write(1, "", 0) == -1)
		return (-1);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			i += ft_conversion(input, element);
		}
		else
			i += write(1, input, 1);
		input++;
	}
	va_end(element);
	return (i);
}
