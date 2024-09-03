#include "../../includes/minishell.h"

int	is_builtin(t_msh *msh, t_cmd *cmd)
 {
	if (!ft_strncmp("cd", cmd->argv[0], 3))
		return (ft_cd(msh), 0);
	if (!ft_strncmp("echo", cmd->argv[0], 5))
		return (ft_echo(msh, cmd->fd_out), 0);
	if (!ft_strncmp("export", cmd->argv[0], 7))
		return (ft_export(msh), 0);
	if (!ft_strncmp("unset", cmd->argv[0], 6))
		return (ft_unset(msh), 0);
	if (!ft_strncmp("pwd", cmd->argv[0], 4))
		return (ft_pwd(msh), 0);
	if (!ft_strncmp("exit", cmd->argv[0], 5))
		return (ft_exit(msh), 0);
	if (!ft_strncmp("env", cmd->argv[0], 4))
		return (ft_env(msh), 0);
	return (1);
}

void	executor(t_msh *msh)
{
	int	fd[2];

	g_signal = 1;
	msh->path = get_path(msh);
	fd[0] = dup(0);
	fd[1] = dup(1);
	if (!msh->path)
		error_msh("Path not found", msh, 130);
	else if (msh->cmd_len == 1)
		one_cmd_handler(msh);
	else
		multiple_cmds(msh, msh->cmd);
	g_signal = 0;
	dup2(0, fd[0]);
	dup2(1, fd[1]);
}
