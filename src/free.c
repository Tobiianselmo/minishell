/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:08:49 by tanselmo          #+#    #+#             */
/*   Updated: 2024/07/01 11:06:46 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!*matrix || !matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}

static void	free_tokens(t_token **tokens)
{
	t_token	*aux;

	if (!*tokens || !tokens)
		return ;
	while (*tokens)
	{
		aux = (*tokens)->next;
		if ((*tokens)->content)
			free((*tokens)->content);
		free(*tokens);
		*tokens = aux;
	}
	*tokens = NULL;
}

static void	free_cmds(t_cmd **cmd)
{
	t_cmd	*aux;

	if (!*cmd || !cmd)
		return ;
	while (*cmd)
	{
		aux = (*cmd)->next;
		if ((*cmd)->fd_in > 2)
			close((*cmd)->fd_in);
		if ((*cmd)->fd_out > 2)
			close((*cmd)->fd_out);
		free_matrix((*cmd)->argv);
		free(*cmd);
		*cmd = aux;
	}
	*cmd = NULL;
}

void	free_msh(t_msh *msh)
{
	if (msh->tokens)
		free_tokens(&msh->tokens);
	if (msh->cmd)
		free_cmds(&msh->cmd);
	if (msh->line)
	{
		free(msh->line);
		msh->line = NULL;
	}
	msh->cmd_len = 0;
}
