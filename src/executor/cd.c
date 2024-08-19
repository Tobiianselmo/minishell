#include "../../includes/minishell.h"

static int	cmd_argc(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->argv[i])
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
	free(new);
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
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (cmd_argc(msh->cmd) > 2)
		error_msh("Minishell: cd: too many arguments", msh, 1);
	else if (msh->cmd->argv[1] == NULL)
		chdir(get_env_cd(msh, "HOME"));
	else if (ft_strncmp(msh->cmd->argv[1], "-", 2) == 0)
	{
		chdir(get_env_cd(msh, "OLDPWD"));
		ft_printf("%s\n", get_env_cd(msh, "OLDPWD"));
	}
	else
	{
		if (chdir(msh->cmd->argv[1]) == -1)
		{
			ft_printf("Minishell: cd: %s: %s\n", msh->cmd->argv[1],
				strerror(errno));
			msh->state = 1;
		}

	}
	set_env(msh, "OLDPWD", pwd);
	pwd = getcwd(NULL, 0);
	set_env(msh, "PWD", pwd);
}
