#include "../../includes/minishell.h"

static int	is_builtin(t_msh *msh)
{
	t_cmd	*cmd;

	cmd = msh->cmd;
	if (!ft_strncmp("cd", cmd->argv[0], 3))
		return (0);
	if (!ft_strncmp("echo", cmd->argv[0], 5))
		return (echo(msh), 0);
	if (!ft_strncmp("export", cmd->argv[0], 7))
		return (0);
	if (!ft_strncmp("unset", cmd->argv[0], 6))
		return (0);
	if (!ft_strncmp("pwd", cmd->argv[0], 4))
		return (0);
	if (!ft_strncmp("exit", cmd->argv[0], 6))
		return (0);
	if (!ft_strncmp("env", cmd->argv[0], 4))
		return (env(msh), 0);
	return (1);
}

void	executor(t_msh *msh)
{
	if (is_builtin(msh))
		printf("no es builtin\n");
}
