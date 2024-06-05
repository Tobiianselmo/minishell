/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:34:19 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/05 21:12:09 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_cmd(t_cmd **cmd, t_token **tokens)
{
	t_cmd	*new_cmd;
	t_token	*tok;
	int		len;

	len = 0;
	tok = *tokens;
	new_cmd = new_node_cmd();
	while (tok && tok->type == T_WORD)
	{
		tok = tok->next;
		len++;
	}
	new_cmd->argv = (char **)malloc(sizeof(char *) * (len));
	if (!new_cmd->argv)
		return ;
	if (cmd_content(new_cmd, tokens) == 0)
	{
		error_msh("Error\n");
		//lst_clear(cmd);
	}
	create_cmd_lst(cmd, new_cmd);
}

/* void	set_infile(t_token **tokens)
{
	if ()
} */

t_cmd	*get_cmd(t_token *tok)
{
	t_token	*tmp;
	t_cmd	*cmd;

	tmp = tok;
	cmd = NULL;
	while (tmp)
	{
		if (tmp->type == T_WORD)
			set_cmd(&cmd, &tmp);
/* 		else if (tmp->type == T_L || tmp->type == T_DL)
			set_infile(&tmp);
		else if (tmp->type == T_G || tmp->type == T_DG)
			set_outfile(&tmp); */
		else if (tmp->type == T_PIPE)
			tmp = tmp->next;
	}
	return (cmd);
}
