#include "../includes/minishell.h"

static int	clean_tokens(t_msh *msh)
{
	if (!msh->tokens || msh->parse_error == 1)
		return (0);
	expand_flag(msh->tokens);
	expand_tokens(&msh->tokens, msh);
	join_tokens(&msh->tokens);
	if (check_tokens(&msh->tokens, msh, 0))
		return (1);
	return (0);
}

void	init_msh(char **envp, t_msh *msh)
{
	msh->env = create_env_lst(envp);
	msh->envp = envp;
	msh->cmd_len = 0;
	msh->parse_error = 0;
	msh->state = 0;
	msh->cmd = NULL;
	msh->tokens = NULL;
	msh->path = NULL;
}

void	get_line(t_msh *msh)
{
	msh->line = readline("Minishell% ");
	if (!msh->line)
		ctrl_d();
	while (msh->line)
	{
		if (msh->line[0] == '\0')
			free(msh->line);
		else
		{
			add_history(msh->line);
			msh->tokens = set_tokens(msh->line, msh);
			if (clean_tokens(msh))
			{
				get_cmd(msh);
				executor(msh);
			}
			free_msh(msh);
		}
		msh->line = readline("Minishell% ");
		if (!msh->line)
			ctrl_d();
	}
	free_msh(msh);
}
