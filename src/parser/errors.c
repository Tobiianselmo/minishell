#include "../includes/minishell.h"

void	error_msh(char *msg, t_msh *msh, int state)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putendl_fd(msg, 2);
	msh->state = state;
}

void	error_files(char *name, char *msg)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

void	error_and_exit(char *name, int state, t_msh *msh)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": No such file or directory", 2);
	free_and_exit("", msh, state, false);
}

void	free_and_exit(char *msg, t_msh *msh, int state, bool print)
{
	if (print == true)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putendl_fd(msg, 2);
	}
	free_env(msh->env);
	free_msh(msh);
	exit(state);
}
