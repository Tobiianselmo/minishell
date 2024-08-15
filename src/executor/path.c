#include "../../includes/minishell.h"

char	**get_path(t_msh *msh)
{
	t_env	*aux;
	char	**path;

	aux = msh->env;
	while (aux)
	{
		if (ft_strncmp(aux->type, "PATH", 5) == 0)
		{
			path = ft_split(aux->content, ':');
			return (path);
		}
		aux = aux->next;
	}
	return (NULL);
}
