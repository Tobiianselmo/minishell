/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:52:28 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/28 12:37:30 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*new_node;

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

t_cmd	*new_node_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->error = 0;
	new->next = NULL;
	return (new);
}

void	create_cmd_lst(t_cmd **cmd, t_cmd *new)
{
	if (!*cmd)
		*cmd = new;
	else
		add_back_cmd(cmd, new);
}

int	cmd_content(t_cmd *new, t_token *tok)
{
	t_token	*aux;
	int		i;

	aux = tok;
	i = 0;
	while (aux && aux->type != T_PIPE)
	{
		if (aux->type == T_G || aux->type == T_DG
			|| aux->type == T_L || aux->type == T_DL)
			aux = aux->next;
		else
		{
			new->argv[i] = ft_strdup(aux->content);
			if (!new->argv[i])
				return (0);
			i++;	
		}
		aux = aux->next;
	}
	new->argv[i] = NULL;
	return (1);
}
