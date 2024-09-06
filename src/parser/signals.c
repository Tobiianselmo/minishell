#include "../includes/minishell.h"

void	ctrl_c(void)
{
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
		write(1, "\n", 1);
}

static void	sig_handler(int signal)
{
	if (signal == SIGINT && (g_signal == 0 || g_signal == 1))
		ctrl_c();
}

void	init_signals(t_msh *msh)
{
	struct sigaction	act;

	act.sa_handler = &sig_handler;
	act.sa_flags = SA_RESTART;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGINT, &act, NULL) == -1)
		error_msh("Error: sigaction", msh, 1);
	act.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &act, NULL) == -1)
		error_msh("Error: sigaction", msh, 1);
	if (sigaction(SIGTSTP, &act, NULL) == -1)
		error_msh("Error: sigaction", msh, 1);
}

void	ctrl_d(void)
{
	ft_putstr_fd("exit\n", 1);
}
