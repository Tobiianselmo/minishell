#include "../includes/minishell.h"

static int	get_flag(t_cmd *cmd, int *i, int *j)
{
	*j = 2;
	while (cmd->argv[*i][*j] == 'n')
		*j += 1;
	if (!cmd->argv[*i][*j])
		return (1);
	else
		return (0);
}

void	ft_echo(t_msh *msh, t_cmd *cmd, int fd)
{
	int	i;
	int	j;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (!cmd)
		return ;
	while (cmd->argv[i] && !(ft_strncmp(cmd->argv[i], "-n", 2)))
	{
		if (get_flag(cmd, &i, &j) == 1)
			n_flag = 1;
		else if (get_flag(cmd, &i, &j) == 0)
			break ;
		i++;
	}
	while (cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i++], fd);
		if (cmd->argv[i])
			ft_putstr_fd(" ", fd);
	}
	if (!n_flag)
		ft_putstr_fd("\n", fd);
	msh->state = 0;
}
