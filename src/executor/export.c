#include "../../includes/minishell.h"

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
			break ;
		}
		aux = aux->next;
	}
	free(new);
}

void	export(t_msh *msh)
{
	(void)msh;
	return ;
}
