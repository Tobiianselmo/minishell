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

void	export(t_msh *msh)
{
	(void)msh;
	return ;
}
