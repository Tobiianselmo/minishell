#include "../../includes/minishell.h"

static bool	all_nbr(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

void	ft_exit(t_msh *msh)
{
	int	fd;

	fd = msh->cmd->fd_out;
	if (!msh->cmd->argv[1])
	{
		error_msh("exit", msh, 0);
		exit(0);
	}
	if (msh->cmd->argv[2] && all_nbr(msh->cmd->argv[1]) == true)
	{
		ft_putendl_fd("exit", fd);
		ft_putstr_fd("minishell: exit: ", fd);
		ft_putstr_fd(msh->cmd->argv[2], fd);
		ft_putendl_fd(": too many arguments", fd);
		msh->state = 1;
		return ;
	}
	if (all_nbr(msh->cmd->argv[1]) == true)
	{
		error_msh("exit", msh, ft_atoi(msh->cmd->argv[1]));
		exit(ft_atoi(msh->cmd->argv[1]));
	}
	else
	{
		error_msh("exit", msh, 2);
		ft_putstr_fd("minishell: exit: ", fd);
		ft_putstr_fd(msh->cmd->argv[1], fd);
		ft_putendl_fd(": numeric argument required", fd);
		exit(2);
	}
}
