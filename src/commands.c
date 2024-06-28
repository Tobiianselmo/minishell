/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:34:19 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/28 16:24:13 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* void	set_cmd(t_msh *msh, t_token **tokens)
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
} */

/* static void	set_infile(t_msh *msh, t_token **tokens)
{
	if ((*tokens)->type == T_L)
	{
		msh->cmd->fd_in = open((*tokens)->next->content, O_RDONLY);
		if (msh->cmd->fd_in == -1)
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
		msh->cmd->fd_out = open((*tokens)->next->content,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (msh->cmd->fd_out == -1)
		{
			error_files((*tokens)->next->content, NO_CFILE);
			msh->flag = 1;
		}
	}
	else if ((*tokens)->type == T_DG)
	{
		msh->cmd->fd_out = open((*tokens)->next->content,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (msh->cmd->fd_out == -1)
		{
			error_files((*tokens)->next->content, NO_CFILE);
			msh->flag = 1;
		}
	}
	*tokens = (*tokens)->next->next;
} */

/* int	get_cmd(t_msh *msh)
{
	t_token	*tmp;

	tmp = msh->tokens;
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
	if (msh->flag == 0)
		return (1);
	else
		return (0);
} */

static int	get_cmd_len(t_token *tok)
{
	t_token	*aux;
	int		len;

	aux = tok;
	len = 0;
	while (aux && aux->type != T_PIPE)
	{
		if (aux->type == T_G || aux->type == T_DG
			|| aux->type == T_L || aux->type == T_DL)
			aux = aux->next;
		else
			len++;
		aux = aux->next;
	}
	return (len);
}

static void	set_outfile(t_token **tok, t_cmd *new)
{
	*tok = (*tok)->next;
	if (new->error == 0)
	{
		if (new->fd_out > 2)
			close(new->fd_out);
		new->fd_out = open((*tok)->content,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (new->fd_out == -1)
		{
			error_files((*tok)->content, NO_CFILE);
			new->error = 1;
		}
	}
	*tok = (*tok)->next;
}

static void	set_append(t_token **tok, t_cmd *new)
{
	*tok = (*tok)->next;
	if (new->error == 0)
	{	
		if (new->fd_out > 2)
			close(new->fd_out);
		new->fd_out = open((*tok)->content,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (new->fd_out == -1)
		{
			error_files((*tok)->content, NO_CFILE);
			new->error = 1;
		}
	}
	*tok = (*tok)->next;
}

static void	set_infile(t_token **tok, t_cmd *new)
{
	*tok = (*tok)->next;
	if (new->fd_in > 2)
		close(new->fd_in);
	new->fd_in = open((*tok)->content, O_RDONLY);
	if (new->fd_in == -1)
	{
		error_files((*tok)->content, NO_FILE);
		new->error = 1;
	}
	*tok = (*tok)->next;
}

static void	set_fd(t_token **tok, t_cmd *new)
{
	new->fd_in = -1;
	new->fd_out = -1;
	while (*tok && (*tok)->type != T_PIPE)
	{
		if ((*tok)->type == T_G)
			set_outfile(tok, new);
		else if ((*tok)->type == T_DG)
			set_append(tok, new);
		else if ((*tok)->type == T_L)
			set_infile(tok, new);
//		else if ((*tok)->type == T_DL)
//			set_heredoc(tok, new);
		else if ((*tok)->type == T_WORD)
			*tok = (*tok)->next;
	}
}

static void	set_cmd(t_msh *msh, t_token **tokens)
{
	t_cmd	*new_cmd;
	t_token	*tok;
	int		len;

	tok = *tokens;
	len = get_cmd_len(*tokens);
	new_cmd = new_node_cmd();
	new_cmd->argv = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_cmd->argv)
		return ;
	if (len > 0)
	{
		if (cmd_content(new_cmd, *tokens) == 0)
		{
			error_msh("Error\n");
			new_cmd->error = 1;
		}
	}
	else
		new_cmd->argv[0] = NULL;
	set_fd(tokens, new_cmd);
	create_cmd_lst(&msh->cmd, new_cmd);
}

int	get_cmd(t_msh *msh)
{
	t_token *tmp;

	tmp = msh->tokens;
	while (tmp)
	{
		if (tmp->type != T_PIPE)
			set_cmd(msh, &tmp);
		else
			tmp = tmp->next;
	}
	return (1);
}
