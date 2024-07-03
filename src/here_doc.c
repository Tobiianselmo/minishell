
#include "../includes/minishell.h"

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
		//expand_heredoc(line, msh);
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