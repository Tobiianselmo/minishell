/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:03:47 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/28 19:42:37 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_back(t_token **lst, t_token *new)
{
	t_token	*new_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_node = *lst;
	while (new_node->next != NULL)
		new_node = new_node->next;
	new_node->next = new;
}

t_token	*new_node(char *content, int type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->type = type;
	new->next = NULL;
	return (new);
}

void	create_tok_lst(t_token **tok, int type, char *content)
{
	t_token	*aux;

	if (!*tok)
		*tok = new_node(content, type);
	else
	{
		aux = new_node(content, type);
		add_back(tok, aux);
	}
	free(content);
}
