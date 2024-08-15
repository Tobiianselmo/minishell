#include "../includes/minishell.h"

static int	get_flag(t_msh *msh, int *i, int *j)
{
	*j = 2;
	while (msh->cmd->argv[*i][*j] == 'n')
		*j += 1;
	if (!msh->cmd->argv[*i][*j])
		return (1);
	else
		return (0);
}

void	ft_echo(t_msh *msh, int fd)
{
	int	i;
	int	j;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (!msh->cmd)
		return ;
	while (msh->cmd->argv[i] && !(ft_strncmp(msh->cmd->argv[i], "-n", 2)))
	{
		if (get_flag(msh, &i, &j) == 1)
			n_flag = 1;
		else if (get_flag(msh, &i, &j) == 0)
			break ;
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
