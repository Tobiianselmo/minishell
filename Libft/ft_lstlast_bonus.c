/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:45:32 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/22 13:07:15 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

/* int main()
{
	t_list *l;
	t_list *actual;

	l = ft_lstnew(ft_strdup("1"));
	l->next = ft_lstnew(ft_strdup("5"));
	l->next = ft_lstnew(ft_strdup("10"));
	actual = ft_lstlast(l);
	printf("%s\n", actual->content);
} */