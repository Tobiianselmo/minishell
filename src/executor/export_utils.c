#include "../../includes/minishell.h"

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

static void	print_var(t_env *aux, char *content)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(aux->type, 1);
	if (content)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(aux->content, 1);
		write(1, "\"\n", 3);
	}
	else
		ft_putstr_fd("\n", 1);
}

void	print_export(t_env *env)
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
		print_var(aux, aux->content);
		index++;
	}

}