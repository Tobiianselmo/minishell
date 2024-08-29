#include "../../includes/minishell.h"

static char	*find_cmd(char **path, char *cmd)
{
	int	i;
	char	*cmd_joined;
	char	*aux;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	while (path[i])
	{
		aux = ft_strjoin(path[i], "/");
		cmd_joined = ft_strjoin(aux, cmd);
		if (access(cmd_joined, F_OK | X_OK) == 0)
		{
			free(aux);
			return (cmd_joined);
		}
		free(aux);
		free(cmd_joined);
		i++;
	}
	return (NULL);
}

static int	is_builtin(t_msh *msh)
{
	t_cmd	*cmd;

	cmd = msh->cmd;
	if (!ft_strncmp("cd", cmd->argv[0], 3))
		return (cd(msh), 0);
	if (!ft_strncmp("echo", cmd->argv[0], 5))
		return (ft_echo(msh, msh->cmd->fd_out), 0);
	if (!ft_strncmp("export", cmd->argv[0], 7))
		return (export(msh), 0);
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

void	one_cmd(t_msh *msh, char **env)
{
	// int		fd_in;
	// int		fd_out;
	char	*cmd_and_path;
	char	*cmd;
	pid_t	pid;

	if (msh->cmd->error == 1)
		return ; /* Not finished */
	if (is_builtin(msh) == 0)
	 	return ;
	else
	{
		cmd = msh->cmd->argv[0];
		cmd_and_path = find_cmd(env, cmd);
		if (!cmd_and_path)
		{
			error_msh("Minishell: Command not found", msh, 127);
			return ;
		}
		pid = fork();
		if (pid < 0)
			error_msh("Error creating pid", msh, 0); /* Test return */
		if (pid == 0)
		{
			if (msh->cmd->fd_in != 0)
				dup2(msh->cmd->fd_in, STDIN_FILENO);
			if (msh->cmd->fd_out != 1)
				dup2(msh->cmd->fd_out, STDOUT_FILENO);
			execve(cmd_and_path, msh->cmd->argv, msh->envp);
		}
		waitpid(pid, NULL, 0);
		free(cmd_and_path);
	}
}
