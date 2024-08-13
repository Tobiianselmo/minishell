#include "../../includes/minishell.h"

void	exp_line(char *str, t_msh *msh)
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
}

void	expand_heredoc(char *line, t_msh *msh)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			exp_line(line, msh);
			break ;
		}
		i++;
	}
}

void	ctrl_c_hd(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", 1);
	exit(130);
}
