#include "../includes/minishell.h"

static void	exp_line(char *str, t_msh *msh)
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

static void	expand_heredoc(char *line, t_msh *msh)
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

static void	here_doc(char *limit, t_cmd *new, t_msh *msh)
{
	char	*line;
	int		fd;
	int		len;

	(void)msh;
	fd = open(".here_doc.tmp", O_WRONLY | O_CREAT, 0644);
	len = ft_strlen(limit);
	line = readline("> ");
	while (line)
	{
		if (ft_strncmp(line, limit, len) == 0 && !line[len])
		{
			free(line);
			break ;
		}
		expand_heredoc(line, msh);
		ft_putendl_fd(line, fd);
		free(line);
		line = readline("> ");
	}
	unlink(".here_doc.tmp");
	new->fd_in = fd;
}

void	set_heredoc(t_token **tok, t_cmd *new, t_msh *msh)
{
	*tok = (*tok)->next;
	if (new->fd_in > 2)
		close(new->fd_in);
	here_doc((*tok)->content, new, msh);
	if (new->fd_in == -1)
	{
		error_files((*tok)->content, NO_FILE);
		new->error = 1;
		msh->state = 1;
	}
	*tok = (*tok)->next;
}
