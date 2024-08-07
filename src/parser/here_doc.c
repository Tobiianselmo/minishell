#include "../includes/minishell.h"

static void	wait_hd(t_cmd *cmd, t_msh *msh, int fd)
{
	int	stat;

	(void)msh;
	waitpid(0, &stat, 0);
	if (WEXITSTATUS(stat))
	{
		cmd->error = 1;
		msh->state = 130;
	}
	close(fd);
	cmd->fd_in = open(".here_doc.tmp", O_RDONLY);
	// if (cmd->fd_in == -1)
	// {
	// 	error_files((*tok)->content, NO_FILE);
	// 	cmd->error = 1;
	// }
	signal(SIGINT, ctrl_c);
}

static void	here_doc(char *limit, t_cmd *new, t_msh *msh, int fd)
{
	char	*line;
	int		len;

	(void)new;
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
	exit(0);
}

void	set_heredoc(t_token **tok, t_cmd *new, t_msh *msh)
{
	pid_t	pid;
	int		fd;

	*tok = (*tok)->next;
	if (new->error == 0)
	{
		if (new->fd_in > 2)
			close(new->fd_in);
		signal(SIGINT, SIG_IGN);
		fd = open(".here_doc.tmp", O_WRONLY | O_CREAT, 0644);
		pid = fork();
		if (pid == 0)
		{
			signal(SIGINT, ctrl_c_hd);
			here_doc((*tok)->content, new, msh, fd);
		}
		else if (pid > 0)
			wait_hd(new, msh, fd);
	}
	*tok = (*tok)->next;
}
