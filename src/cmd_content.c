/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:52:28 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/05 18:53:24 by tanselmo         ###   ########.fr       */
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

int	cmd_content(t_cmd *new, t_token **tok)
{
	int	i;

	i = 0;
	while (*tok && (*tok)->type == T_WORD)
	{
		new->argv[i] = ft_strdup((*tok)->content);
		if (!new->argv[i])
		{
			//free_matrix(new->argv);
			return (0);
		}
		i++;
		*tok = (*tok)->next;
	}
	new->argv[i] = NULL;
	new->cmd = ft_strdup(new->argv[0]);
	if (!new->cmd)
		return (0);
	return (1);
}
