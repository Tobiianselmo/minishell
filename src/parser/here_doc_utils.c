#include "../../includes/minishell.h"

char	*exp_line(char *str, t_msh *msh)
{
	char	*aux;
	char	*line;
	int		i;

	line = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			aux = get_noexp_var(str, &i);
		else if (str[i] == '$' && str[i + 1] == '~')
		{
			aux = ft_strdup("$~");
			i += 2;
		}
		else if (str[i] == '$')
			aux = get_exp(str, &i, msh);
		else
			aux = get_word(str, &i);
		line = strjoin_msh(line, aux);
	}
	free(str);
	str = ft_strdup(line);
	free(line);
	return (str);
}

char	*expand_heredoc(char *line, t_msh *msh)
{
	int		i;
	char	*aux;

	i = 0;
	aux = ft_strdup(line);
	free(line);
	while (aux[i])
	{
		if (aux[i] == '$')
			return (exp_line(aux, msh));
		i++;
	}
	return (aux);
}

void	ctrl_c_hd(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", 1);
	exit(130);
}
