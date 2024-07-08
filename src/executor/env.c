#include "../includes/minishell.h"

void	env(t_msh *msh)
{
	t_env	*tmp;
	
	tmp = msh->env;
	if (!tmp)
		return ;
	while (tmp)
	{
		printf("%s=%s\n", tmp->type, tmp->content);
		tmp = tmp->next;
	}
	msh->cmd = msh->cmd->next;
}
