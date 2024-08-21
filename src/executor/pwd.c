#include "../../includes/minishell.h"

void	ft_pwd(t_msh *msh)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return(error_msh("Minishell: pwd: Cannot find the pwd", msh, 0)); /* The state is not zero, it's only a test */
	ft_putendl_fd(pwd, msh->cmd->fd_out);
	free(pwd);
}
