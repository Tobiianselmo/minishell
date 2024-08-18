#include "../../includes/minishell.h"

static int	cmd_argc(t_msh *msh)
{
	int		i;

	i = 0;
	while (msh->cmd->argv[i])
		i++;
	return (i);
}

static	void	set_env(t_msh *msh, char *var, char *new)
{
	t_env	*aux;

	aux = msh->env;
	while (aux)
	{
		if (ft_strncmp(var, aux->type, ft_strlen(var)) == 0)
		{
			free(aux->content);
			aux->content = ft_strdup(new);
			break ;
		}
		aux = aux->next;
	}
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

void	cd(t_msh *msh)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = getcwd(NULL, 0);
	if (cmd_argc(msh) > 2)
		error_msh("Minishell: cd: too many arguments", msh, 1);
	else if (msh->cmd->argv[1] == NULL)
		chdir(get_env_cd(msh, "HOME"));
	else if (ft_strncmp(msh->cmd->argv[1], "-", 2) == 0)
	{
		chdir(get_env_cd(msh, "OLDPWD"));
		ft_printf("%s\n", get_env_cd(msh, "OLDPWD"));
	}
	else
		chdir(msh->cmd->argv[1]);
	set_env(msh, "OLDPWD", oldpwd);
	pwd = getcwd(NULL, 0);
	set_env(msh, "PWD", pwd);
	free(oldpwd);
	free(pwd);
}
