#include "../../includes/minishell.h"

char	*find_cmd(char **path, char *cmd)
{
	int		i;
	char	*cmd_joined;
	char	*aux;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	if (!path)
		error_and_exit(cmd, 127);
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

void	execute_cmd(t_msh *msh, t_cmd *cmd, char **path)
{
	char	*cmd_and_path;

	if (!cmd->argv[0])
		exit(EXIT_SUCCESS);
	cmd_and_path = find_cmd(path, cmd->argv[0]);
	if (!cmd_and_path)
		free_and_exit("Command not found", msh, 127, true);
	execve(cmd_and_path, cmd->argv, msh->envp);
	free(cmd_and_path);
	free_and_exit("execve failed", msh, EXIT_FAILURE, true);
}

void	one_cmd_handler(t_msh *msh)
{
	pid_t	pid;

	if (msh->cmd->error == 1)
		return ;
	if (is_builtin(msh, msh->cmd) == 0)
		return ;
	pid = fork();
	if (pid < 0)
		error_msh("Error creating pid", msh, 0);
	if (pid == 0)
	{
		if (msh->cmd->fd_in != 0)
			dup2(msh->cmd->fd_in, STDIN_FILENO);
		if (msh->cmd->fd_out != 1)
			dup2(msh->cmd->fd_out, STDOUT_FILENO);
		execute_cmd(msh, msh->cmd, msh->path);
		exit(EXIT_SUCCESS);
	}
	wait_handler(msh, pid);
}
