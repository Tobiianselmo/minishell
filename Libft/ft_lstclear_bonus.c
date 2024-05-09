/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:45:57 by tanselmo          #+#    #+#             */
/*   Updated: 2023/12/22 17:31:56 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (lst != NULL && del != NULL)
	{
		while (*lst != NULL)
		{
			node = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = node;
		}
	}
}
