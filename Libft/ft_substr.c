/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:59:51 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:40 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;
	size_t	i;

	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	if (slen < start + len)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/* int main()
{
	char const *string = "";
	unsigned int start = 1;
	
	printf("%s\n", ft_substr(string, start, 1));
	return (0);
} */