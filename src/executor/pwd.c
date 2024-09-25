#include "../../includes/minishell.h"

void	ft_pwd(t_msh *msh, t_cmd *cmd)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (error_msh("pwd: Cannot find the pwd", msh, 0));
	ft_putendl_fd(pwd, cmd->fd_out);
	free(pwd);
	msh->state = 0;
}
