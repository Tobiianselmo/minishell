#include "../includes/minishell.h"

void	add_env(t_msh *msh, char *var, char *content)
{
	t_env	*aux;

	aux = msh->env;
	while (aux->next)
		aux = aux->next;
	aux->next = malloc(sizeof(t_env));
	if (!aux->next)
		return ;
	aux = aux->next;
	aux->type = ft_strdup(var);
	if (content)
		aux->content = ft_strdup(content);
	else
		aux->content = NULL;
	aux->next = NULL;
}

void	set_env(t_msh *msh, char *var, char *new)
{
	t_env	*aux;

	aux = msh->env;
	if (!new)
		return ;
	while (aux)
	{
		if (ft_strncmp(var, aux->type, ft_strlen(var) + 1) == 0)
		{
			free(aux->content);
			aux->content = ft_strdup(new);
			return ;
		}
		aux = aux->next;
	}
	add_env(msh, var, new);
}

char	*get_env(t_msh *msh, char *var)
{
	t_env	*aux;

	aux = msh->env;
	while (aux)
	{
		if (ft_strncmp(var, aux->type, ft_strlen(var) + 1) == 0)
			return (aux->content);
		aux = aux->next;
	}
	return (NULL);
}

char	*get_env_type(t_msh *msh, char *var)
{
	t_env	*aux;

	aux = msh->env;
	while (aux)
	{
		if (ft_strncmp(var, aux->type, ft_strlen(var) + 1) == 0)
			return (aux->type);
		aux = aux->next;
	}
	return (NULL);
}

void	ft_env(t_msh *msh, t_cmd *cmd, char *next)
{
	t_env	*tmp;

	tmp = msh->env;
	if (!tmp)
		return ;
	if (next)
	{
		ft_putstr_fd("env: '", 2);
		ft_putstr_fd(next, 2);
		ft_putendl_fd("': No such file or directory", 2);
		msh->state = 127;
		return ;
	}
	while (tmp)
	{
		if (tmp->content)
		{
			ft_putstr_fd(tmp->type, cmd->fd_out);
			ft_putstr_fd("=", cmd->fd_out);
			ft_putendl_fd(tmp->content, cmd->fd_out);
		}
		tmp = tmp->next;
	}
	msh->state = 0;
}
