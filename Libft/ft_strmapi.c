/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:30:25 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/21 12:46:11 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	char	*result;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	result = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (result);
}

/* char lowertoupper(unsigned int i, char c)
{
	i = 0;
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

int main() {
    char original[] = "Argentina";
    char *result;

    result = ft_strmapi(original, &lowertoupper);
    printf("%s\n", result);
    return 0;
} */