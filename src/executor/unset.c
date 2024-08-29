#include "../../includes/minishell.h"

static void	free_env_node(t_env *env)
{
	free(env->type);
	free(env->content);
	free(env);
}

static void	delete_var(t_msh *msh, char *var)
{
	t_env	*curr;
	t_env	*prev;

	prev = msh->env;
	curr = msh->env->next;
	if (ft_strncmp(prev->type, var, ft_strlen(var) + 1) == 0)
	{
		free_env_node(prev);
		msh->env = curr;
		return ;
	}
	while (curr)
	{
		if (ft_strncmp(curr->type, var, ft_strlen(var) + 1) == 0)
		{
			prev->next = curr->next;
			free_env_node(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	ft_unset(t_msh *msh)
{
	int		i;

	i = 0;
	while (msh->cmd->argv[++i])
		delete_var(msh, msh->cmd->argv[i]);
}
