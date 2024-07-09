#include "../includes/minishell.h"

void	echo(t_msh *msh)
{
	int	i;
	int	n_flag;
	int	fd;

	i = 1;
	n_flag = 0;
	fd = msh->cmd->fd_out;
	if (!msh->cmd)
		return ;
	while (!ft_strncmp(msh->cmd->argv[i], "-n", 3))
	{
		n_flag = 1;
		i++;
	}
	while (msh->cmd->argv[i])
	{
		ft_putstr_fd(msh->cmd->argv[i++], fd);
		if (msh->cmd->argv[i])
			ft_putstr_fd(" ", fd);
	}
	if (!n_flag)
		ft_putstr_fd("\n", fd);
	msh->cmd = msh->cmd->next;
}
