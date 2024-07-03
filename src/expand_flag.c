
#include "../includes/minishell.h"

static int	check_dollar(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

static int	check_home(char *line)
{
	if (line[0] == '~' && !line[1])
		return (1);
	else if (line[0] == '\\' && line[1] == '~')
		return (2);
	return (0);
}

static void	sup_backslash(char *line)
{
	char	*aux;

	aux = ft_substr(line, 1, ft_strlen(line));
	free(line);
	line = ft_strdup(aux);
	free(aux);
}

void	expand_flag(t_token *tok)
{
	t_token	*aux;

	aux = tok;
	while (aux)
	{
		aux->exp = 0;
		if (aux->type == T_WORD || aux->type == T_DQ)
		{
			if (check_dollar(aux->content) == 1)
				aux->exp = 1;
			else if (check_home(aux->content) == 1)
				aux->exp = 2;
			else if (check_home(aux->content) == 2)
				sup_backslash(aux->content);
		}
		aux = aux->next;
	}
}
