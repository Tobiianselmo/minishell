#include "../../includes/minishell.h"

static void	set_cmd_index(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

int	is_builtin(t_msh *msh, t_cmd *cmd)
{
	if (!ft_strncmp("cd", cmd->argv[0], 3))
		return (ft_cd(msh, cmd), 0);
	if (!ft_strncmp("echo", cmd->argv[0], 5))
		return (ft_echo(msh, cmd, cmd->fd_out), 0);
	if (!ft_strncmp("export", cmd->argv[0], 7))
		return (ft_export(msh, cmd), 0);
	if (!ft_strncmp("unset", cmd->argv[0], 6))
		return (ft_unset(msh, cmd), 0);
	if (!ft_strncmp("pwd", cmd->argv[0], 4))
		return (ft_pwd(msh, cmd), 0);
	if (!ft_strncmp("exit", cmd->argv[0], 5))
		return (ft_exit(msh, cmd), 0);
	if (!ft_strncmp("env", cmd->argv[0], 4))
		return (ft_env(msh, cmd), 0);
	return (1);
}

void	executor(t_msh *msh)
{
	int	fd[2];
	int	fd_in;

	g_signal = 1;
	fd[0] = dup(0);
	fd[1] = dup(1);
	set_cmd_index(msh->cmd);
	fd_in = msh->cmd->fd_in;
	msh->path = get_path(msh);
	if (msh->cmd_len == 1)
		one_cmd_handler(msh);
	else
		multiple_cmds(msh, fd_in);
	g_signal = 0;
	dup2(fd[0], 0);
	dup2(fd[1], 1);
}
