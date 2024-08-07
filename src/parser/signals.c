#include "../includes/minishell.h"

void	ctrl_c(int signal)
{
	(void)signal;
	if (g_signal == 0) // Prompt
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_signal == 1) // Ejecucion(esperando mensaje)
		write(1, "\n", 1);
}

void	init_signals(void)
{
	signal(SIGTSTP, SIG_IGN); // ctrl + z
	signal(SIGQUIT, SIG_IGN); // ctrl + backslash
	signal(SIGINT, ctrl_c); //ctrl + c
}

void	ctrl_d(void)
{
	ft_putstr_fd("exit\n", 1);
}
