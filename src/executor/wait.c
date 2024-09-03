#include "../../includes/minishell.h"

void	wait_handler(t_msh *msh, pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	msh->state = WEXITSTATUS(status);
}
