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
	if (signal == SIGQUIT && g_signal == 1)
		ft_putendl_fd("Quit (core dumped)", 2);
}

void init_signals(t_msh *msh)
{
    struct sigaction act;

    act.sa_handler = &sig_handler;
    act.sa_flags = SA_RESTART;
    sigemptyset(&act.sa_mask);
    if (sigaction(SIGINT, &act, NULL) == -1)
        error_msh("Error: sigaction", msh, 1);
    if (g_signal == 0)
    {
        act.sa_handler = SIG_IGN;
        if (sigaction(SIGQUIT, &act, NULL) == -1)
            error_msh("Error: sigaction", msh, 1);
    }
	else if (g_signal == 1)
	{
		act.sa_handler = &sig_handler;
		if (sigaction(SIGQUIT, &act, NULL) == -1)
            error_msh("Error: sigaction", msh, 1);
	}
    act.sa_handler = SIG_IGN;
    if (sigaction(SIGTSTP, &act, NULL) == -1)
        error_msh("Error: sigaction", msh, 1);
}

void	ctrl_d(void)
{
	ft_putstr_fd("exit\n", 1);
}

// void	init_signals(t_msh *msh)
// {
// 	struct sigaction	act;

// 	act.sa_handler = &sig_handler;
// 	act.sa_flags = SA_RESTART;
// 	sigemptyset(&act.sa_mask);
// 	if (sigaction(SIGINT, &act, NULL) == -1)
// 		error_msh("Error: sigaction", msh, 1);	
// 	act.sa_handler = SIG_IGN;
// 	if (sigaction(SIGQUIT, &act, NULL) == -1)
// 		error_msh("Error: sigaction", msh, 1);
// 	if (sigaction(SIGTSTP, &act, NULL) == -1)
// 		error_msh("Error: sigaction", msh, 1);
// }



// void ctrl_c(void)
// {
// 	if (g_signal == 0)
// 	{
// 		// Line Mode: Handle SIGINT (Ctrl-C)
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 		write(1, "\n", 1);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// 	else if (g_signal == 1)
// 	{
// 		// Executor Mode: Handle SIGINT
// 		write(1, "\n", 1);
// 	}
// }

// void handle_sigquit(void)
// {
// 	if (g_signal == 1)  // Executor Mode
// 	{
// 		// Print message when SIGQUIT is received in Executor Mode
// 		ft_putendl_fd("Quit (core dumped)", 2);
// 		exit(131);
// 		// Optionally, you can terminate the process or handle it as you see fit
// 		// For example, if you want to abort, use:
// 		// abort();
// 	}
// 	// In Line Mode (g_signal == 0), SIGQUIT is ignored as it's set to SIG_IGN
// }

// static void sig_handler(int signal)
// {
//     if (g_signal == 1)
//        ft_putstr_fd("Executor Mode active\n", 2);  // Debug message

//     if (signal == SIGINT && (g_signal == 0 || g_signal == 1))
//         ctrl_c();
//     else if (signal == SIGQUIT && g_signal == 1)
//     {
//         printf("SIGQUIT received in Executor Mode\n");  // Debug message
//         handle_sigquit();
//     }
// }


// void init_signals(t_msh *msh)
// {
// 	struct sigaction act;

// 	// Handle SIGINT
// 	act.sa_handler = &sig_handler;
// 	act.sa_flags = SA_RESTART;
// 	sigemptyset(&act.sa_mask);
// 	if (sigaction(SIGINT, &act, NULL) == -1)
// 		error_msh("Error: sigaction", msh, 1);

// 	// Handle SIGQUIT based on g_signal mode
// 	if (g_signal == 0)  // Line Mode
// 	{
// 		// Ignore SIGQUIT
// 		act.sa_handler = SIG_IGN;
// 	}
// 	else if (g_signal == 1)  // Executor Mode
// 	{
// 		// Use sig_handler to handle SIGQUIT
// 		act.sa_handler = &sig_handler;
// 	}

// 	if (sigaction(SIGQUIT, &act, NULL) == -1)
// 		error_msh("Error: sigaction", msh, 1);

// 	// You can add handling for SIGTSTP (Ctrl-Z) if needed in a similar way
// 	if (sigaction(SIGTSTP, &act, NULL) == -1)
// 		error_msh("Error: sigaction", msh, 1);
// }
