#include "../../includes/minishell.h"

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

static int	env_lstsize(t_env *lst)
{
	t_env	*new;
	int		size;

	new = lst;
	size = 0;
	while (new != NULL)
	{
		size++;
		new = new->next;
	}
	return (size);
}

static int	get_var_index(t_env *list, t_env *tmp)
{
	t_env	*aux;
	int		index;

	aux = list;
	index = 0;
	while (aux)
	{
		if (ft_strncmp(tmp->type, aux->type, ft_strlen(tmp->type) + 1) > 0)
			index++;
		aux = aux->next;
	}
	return (index);
}

static void	print_export(t_env *env)
{
	t_env	*aux;
	int		index;

	aux = env;
	index = 0;
	while (aux)
	{
		aux->index = get_var_index(env, aux);
		aux = aux->next;
	}
	while (index < env_lstsize(env))
	{
		aux = env;
		while (index != aux->index)
			aux = aux->next;
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(aux->type, 1);
		if (aux->content)
		{
			ft_putstr_fd("=", 1);
			ft_putendl_fd(aux->content, 1);
		}
		else
			ft_putstr_fd("\n", 1);
		index++;
	}

}

void	export(t_msh *msh)
{
	if (!msh->cmd->argv[1])
		print_export(msh->env);
}
