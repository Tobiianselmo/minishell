/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:45:22 by tanselmo          #+#    #+#             */
/*   Updated: 2024/01/12 17:26:52 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* void *multiply_by_2(void *content)
{
	int *value;

	value = (int *)content;
	*value *= 2;
	return (content);
}

void delete(void *content)
{
	free(content);
}

int main()
{
    t_list *l = NULL;
    t_list *actual;
    int arr[] = {1, 2, 3, 4, 5, 0};
    int i = 0;

    while (arr[i])
    {
        t_list *new_node = ft_lstnew(&arr[i]);
        ft_lstadd_back(&l, new_node);
        i++;
    }
    actual = ft_lstmap(l, multiply_by_2, delete);
    i = 0;
    while (actual)
    {
        printf("\'%d\'\n", *(int*)actual->content);
        actual = actual->next;
    }
} */