#include "../../includes/minishell.h"

static char	*find_cmd(char **path, char *cmd)
{
	int		i;
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

static void	execute_cmd(t_msh *msh, t_cmd *cmd, char **path)
{
	char	*cmd_and_path;

	cmd_and_path = find_cmd(path, cmd->argv[0]);
	if (!cmd_and_path)
	{
		error_msh("Minishell: Command not found", msh, 127);
		exit(127);
	}
	execve(cmd_and_path, msh->cmd->argv, msh->envp);
	perror("execve failed");
	free(cmd_and_path);
	exit(EXIT_FAILURE);
}

static void	create_child(t_msh *msh, t_cmd *cmd, int i)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd))
		error_msh("Error creating pipe in childproc", msh, 0); /* Test */
	pid = fork();
	if (pid < 0)
		error_msh("Error creating child process", msh, 0); /* Test */
	if (pid == 0)
	{
		if (i != 0)
		{
			if (cmd->fd_in != 0)
			{
				dup2(fd[0], 0);
				close(cmd->fd_in);
			}
		}
		if (!cmd->next)
			dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execute_cmd(msh, cmd, msh->path);
	}
	wait_handler(msh, pid);
	close(fd[1]);
}

void	multiple_cmds(t_msh *msh, t_cmd *cmd)
{
	int		i;

	i = 0;
	if (cmd->fd_in != 0)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out != 1)
		dup2(cmd->fd_out, STDOUT_FILENO);
	while (cmd)
	{
		create_child(msh, cmd, i);
		cmd = cmd->next;
		i++;
	}
}
