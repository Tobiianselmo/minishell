#include "../../includes/minishell.h"

static int	cmd_argc(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[i])
		i++;
	return (i);
}

static void	cd_errors(t_msh *msh, char *path)
{
	if (ft_strncmp(path, "HOME", 5) == 0 || path == NULL)
		error_msh("Minishell: cd: HOME not set", msh, 1);
	else if (ft_strncmp(path, "OLDPWD", 6) == 0)
		error_msh("Minishell: cd: OLDPWD not set", msh, 1);
	else
	{
		ft_printf("Minishell: cd: %s: %s\n", path, strerror(errno));
		msh->state = 1;
	}
}


int static	chdir_handle(t_msh *msh)
{
	if (cmd_argc(msh->cmd) > 2)
		error_msh("Minishell: cd: too many arguments", msh, 1);
	else if (msh->cmd->argv[1] == NULL)
	{
		if (chdir(get_env(msh, "HOME")) == -1)
			return (cd_errors(msh, get_env(msh, "HOME")), 1);
	}
	else if (ft_strncmp(msh->cmd->argv[1], "-", 2) == 0)
	{
		if (chdir(get_env(msh, "OLDPWD")) == -1)
			return (cd_errors(msh, "OLDPWD"), 1);
		else
			ft_printf("%s\n", get_env(msh, "OLDPWD"));
	}
	else
		if (chdir(msh->cmd->argv[1]) == -1)
			return (cd_errors(msh, msh->cmd->argv[1]), 1);
	return (0);
}

void	cd(t_msh *msh)
{
	char	*pwd;
	char	*aux;

	aux = NULL;
	pwd = get_env(msh, "PWD");
	if (chdir_handle(msh) == 1)
		return ;
	set_env(msh, "OLDPWD", pwd);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		error_msh("Minishell: cd: getcwd: cannot access parent directories",
			msh, 1);
		aux = ft_strjoin("/", msh->cmd->argv[1]);
		set_env(msh, "PWD", ft_strjoin(get_env(msh, "PWD"), aux));
		return (free(aux));
	}
	set_env(msh, "PWD", pwd);
	free(pwd);
}
