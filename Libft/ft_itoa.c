/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:02:49 by tanselmo          #+#    #+#             */
/*   Updated: 2024/01/19 15:56:54 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_numbers(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*int_to_str(int n, int len, int i)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
		i++;
	}
	result[len] = '\0';
	while (len > i)
	{
		result[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*result;
	int		j;

	j = 0;
	i = 0;
	len = count_numbers(n);
	if (n == -2147483648)
	{
		n += 1;
		j = 1;
	}
	result = int_to_str(n, len, i);
	if (!result)
		return (NULL);
	if (j == 1)
		result[len - 1] += 1;
	return (result);
}

/* int	main ()
{
	int	n;

	n = -2147483648;
	printf("%s\n", ft_itoa(n));
	return (0);
} */