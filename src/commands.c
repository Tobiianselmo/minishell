/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:34:19 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/13 15:08:35 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_cmd(t_msh *msh, t_token **tokens)
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
	new_cmd->argv = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_cmd->argv)
		return ;
	if (cmd_content(new_cmd, tokens) == 0)
	{
		error_msh("Error\n");
		msh->flag = 1;
	}
	create_cmd_lst(&msh->cmd, new_cmd);
}

static void	set_infile(t_msh *msh, t_token **tokens)
{
	if ((*tokens)->type == T_L)
	{
		msh->fd_in = open((*tokens)->next->content, O_RDONLY);
		if (msh->fd_in == -1)
		{
			error_files((*tokens)->next->content, NO_FILE);
			msh->flag = 1;
		}
	}
	else
	{
		printf("funcion here doc faltante xd\n");
	}
	*tokens = (*tokens)->next->next;
}

static void	set_outfile(t_msh *msh, t_token **tokens)
{
	if ((*tokens)->type == T_G)
	{
		msh->fd_out = open((*tokens)->next->content,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (msh->fd_out == -1)
		{
			error_files((*tokens)->next->content, NO_CFILE);
			msh->flag = 1;
		}
	}
	else if ((*tokens)->type == T_DG)
	{
		msh->fd_out = open((*tokens)->next->content,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (msh->fd_out == -1)
		{
			error_files((*tokens)->next->content, NO_CFILE);
			msh->flag = 1;
		}
	}
	*tokens = (*tokens)->next->next;
}

int	get_cmd(t_msh *msh)
{
	t_token	*tmp;
	t_cmd	*cmd;

	tmp = msh->tokens;
	cmd = NULL;
	while (tmp)
	{
		if (tmp->type == T_WORD || tmp->type == T_Q || tmp->type == T_DQ)
			set_cmd(msh, &tmp);
		else if (tmp->type == T_L || tmp->type == T_DL)
			set_infile(msh, &tmp);
		else if (tmp->type == T_G || tmp->type == T_DG)
			set_outfile(msh, &tmp);
		else if (tmp->type == T_PIPE)
			tmp = tmp->next;
	}
	msh->cmd = cmd;
	if (msh->flag == 0)
		return (1);
	else
		return (0);
}
