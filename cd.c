#include "../../includes/minishell.h"

static int	cmd_argc(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->argv[i])
		i++;
	return (i);
}

static char	*get_env_cd(t_msh *msh, char *var)
{
	t_env	*aux;

	aux = msh->env;
	while (aux)
	{
		if (ft_strncmp(var, aux->type, ft_strlen(var)) == 0)
			return (aux->content);
		aux = aux->next;
	}
	return (NULL);
}

static void	cd_errors(t_msh *msh, char *path)
{
	if (ft_strncmp(path, "HOME", 5) == 0 || path == NULL)
	{
		ft_printf("Minishell: cd: HOME not set\n");
		msh->state = 1;
	}
	else if (ft_strncmp(path, "OLDPWD", 6) == 0)
	{
		ft_printf("Minishell: cd: OLDPWD not set\n");
		msh->state = 1;
	}
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
		if (chdir(get_env_cd(msh, "HOME")) == -1)
			return (cd_errors(msh, get_env_cd(msh, "HOME")), 1);
	}
	else if (ft_strncmp(msh->cmd->argv[1], "-", 2) == 0)
	{
		if (chdir(get_env_cd(msh, "OLDPWD")) == -1)
			return (cd_errors(msh, "OLDPWD"), 1);
		else
			ft_printf("%s\n", get_env_cd(msh, "OLDPWD"));
	}
	else
		if (chdir(msh->cmd->argv[1]) == -1)
			return (cd_errors(msh, msh->cmd->argv[1]), 1);
	return (0);
}

void	cd(t_msh *msh)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (chdir_handle(msh) == 1)
		return (free(pwd), (void)0);
	printf("pwd: %s\n", pwd);
	set_env(msh, "OLDPWD", pwd);
	pwd = getcwd(NULL, 0);
	set_env(msh, "PWD", pwd);
}
