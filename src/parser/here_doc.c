#include "../includes/minishell.h"

static void	new_handler(int sig)
{
	if (sig == SIGINT)
		ctrl_c_hd(sig);
}

static void	handle_ctrl_c(t_msh *msh)
{
	struct sigaction	new_act;

	new_act.sa_handler = &new_handler;
	new_act.sa_flags = SA_RESTART;
	sigemptyset(&new_act.sa_mask);
	if (sigaction(SIGINT, &new_act, NULL) == -1)
		error_msh("Error: sigaction", msh, 1);
}

static void	wait_hd(t_token *tok, t_cmd *cmd, t_msh *msh, int fd)
{
	int	stat;

	(void)msh;
	waitpid(0, &stat, 0);
	if (WEXITSTATUS(stat) == 130)
	{
		cmd->error = 1;
		msh->state = 130;
	}
	else if (WEXITSTATUS(stat) == 1)
	{
		ft_putstr_fd(CTRLD_HD, 1);
		ft_putstr_fd(tok->content, 1);
		ft_putendl_fd("')", 1);
	}
	close(fd);
	cmd->fd_in = open(".here_doc.tmp", O_RDONLY);
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
		line = expand_heredoc(line, msh);
		if (line)
		{
			ft_putendl_fd(line, fd);
			free(line);
		}
		line = readline("> ");
	}
	if (!line)
		exit(1);
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
		fd = open(".here_doc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		g_signal = 2;
		pid = fork();
		if (pid == 0)
		{
			handle_ctrl_c(msh);
			here_doc((*tok)->content, new, msh, fd);
		}
		else if (pid > 0)
			wait_hd(*tok, new, msh, fd);
		g_signal = 0;
	}
	*tok = (*tok)->next;
}
