#include "../includes/minishell.h"

void	env(t_msh *msh)
{
	t_env	*tmp;
	int		fd;
	
	tmp = msh->env;
	fd = msh->cmd->fd_out;
	if (!tmp)
		return ;
	while (tmp)
	{
		ft_putstr_fd(tmp->type, fd);
		ft_putstr_fd("=", fd);
		ft_putendl_fd(tmp->content, fd);
		tmp = tmp->next;
	}
	msh->cmd = msh->cmd->next;
}
