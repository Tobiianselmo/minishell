/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:46:43 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/22 13:02:40 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_node = *lst;
	while (new_node->next != NULL)
	{
		new_node = new_node->next;
	}
	new_node->next = new;
}
