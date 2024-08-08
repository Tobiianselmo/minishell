#include "../includes/minishell.h"

int	g_signal;

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh;

	(void)argc;
	(void)argv;
	init_signals();
	init_msh(envp, &msh);
	get_line(&msh);
	free_env(msh.env);
	return (0);
}
