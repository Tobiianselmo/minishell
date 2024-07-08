#include "../includes/minishell.h"

static void	ctrl_c(int signal)
{
	(void)signal;
	if (g_signal == 0)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_signal == 1)
		ft_putstr_fd("\n", 1);
}

void	init_signals(void)
{
	signal(SIGTSTP, SIG_IGN); // ctrl + z
	signal(SIGQUIT, SIG_IGN); // ctrl + /
	signal(SIGINT, ctrl_c); //ctrl + c
}
