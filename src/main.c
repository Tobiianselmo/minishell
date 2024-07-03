
#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;

	(void)argc;
	(void)argv;
	init_msh(envp, &msh);
	get_line(&msh);
	return (0);
}
