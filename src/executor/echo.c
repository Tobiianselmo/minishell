#include "../includes/minishell.h"

void	echo(t_msh *msh)
{
	int	i;

	i = 1;
	if (!msh->cmd)
		return ;
	while (msh->cmd->argv[i])
	{
		printf("%s", msh->cmd->argv[i++]);
		if (msh->cmd->argv[i])
			printf(" ");
	}
	msh->cmd = msh->cmd->next;
	printf("\n");
}
