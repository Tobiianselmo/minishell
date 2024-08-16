#include "../../includes/minishell.h"

void	executor(t_msh *msh)
{
	g_signal = 1;
	msh->path = get_path(msh);
	if (!msh->path)
		error_msh("Path not found", msh, 130);
	else if (msh->cmd_len == 1)
		one_cmd(msh, msh->path);
	g_signal = 0;
}
