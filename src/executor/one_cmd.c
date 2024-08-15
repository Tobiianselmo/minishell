#include "../../includes/minishell.h"

static char	*find_cmd(char **path, char *cmd)
{
	int	i;
	int	j;
	char	*cmd_joined;
	char	*aux;

	i = 0;
	j = 0;
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

void	one_cmd(t_msh *msh, char **env)
{
	char	*cmd_and_path;
	char	*cmd;

	if (msh->cmd->error == 1)
		return ;
	cmd = msh->cmd->argv[0];
	cmd_and_path = find_cmd(env, cmd);
	if (!cmd_and_path)
		error_msh("Command not found", msh, 127);
	printf("ruta: %s\n", cmd_and_path);
	return ;
}
