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
	aux->content = ft_strdup(content);
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
		if (ft_strncmp(var, aux->type, ft_strlen(var)) == 0)
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

void	ft_env(t_msh *msh)
{
	t_env	*tmp;
	int		fd;

	tmp = msh->env;
	fd = msh->cmd->fd_out;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (tmp->content)
		{
			ft_putstr_fd(tmp->type, fd);
			ft_putstr_fd("=", fd);
			ft_putendl_fd(tmp->content, fd);
		}
		tmp = tmp->next;
	}
}
