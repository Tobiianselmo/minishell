#include "../includes/minishell.h"

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
		{
			if (access(".here_doc.tmp", F_OK) == 0)
				unlink(".here_doc.tmp");
			close((*cmd)->fd_in);
		}
		if ((*cmd)->fd_out > 2)
			close((*cmd)->fd_out);
		free_matrix((*cmd)->argv);
		free(*cmd);
		*cmd = aux;
	}
	*cmd = NULL;
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
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

void	free_env(t_env *env)
{
	t_env	*aux;

	if (!env)
		return ;
	while (env)
	{
		aux = env->next;
		free(env->type);
		free(env->content);
		free(env);
		env = aux;
	}
}
