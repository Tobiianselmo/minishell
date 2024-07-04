#include "../includes/minishell.h"

void	set_pipe_tok(char *line, int *i, t_token **tokens)
{
	if (line[*i])
	{
		create_tok_lst(tokens, T_PIPE, ft_strdup("|"), 0);
		*i += 1;
	}
}

void	set_g_tok(char *line, int *i, t_token **tokens)
{
	if (line[*i])
	{
		if (line[*i + 1] == '>')
		{
			create_tok_lst(tokens, T_DG, ft_strdup(">>"), 0);
			*i += 2;
		}
		else
		{
			create_tok_lst(tokens, T_G, ft_strdup(">"), 0);
			*i += 1;
		}
	}
}

void	set_l_tok(char *line, int *i, t_token **tokens)
{
	if (line[*i])
	{
		if (line[*i + 1] == '<')
		{
			create_tok_lst(tokens, T_DL, ft_strdup("<<"), 0);
			*i += 2;
		}
		else
		{
			create_tok_lst(tokens, T_L, ft_strdup("<"), 0);
			*i += 1;
		}
	}
}

void	set_q_tok(char *line, int *i, t_token **tokens, t_msh *msh)
{
	int	start;
	int	flag;

	flag = 0;
	start = *i + 1;
	if (line[*i])
	{
		if (*i > 0 && line[*i - 1] != ' ')
			flag = 1;
		*i += 1;
		while (line[*i] && line[*i] != '\'')
			*i += 1;
		if (line[*i] == '\'')
		{
			create_tok_lst(tokens, T_Q, ft_substr(line, start,
					(*i - start)), flag);
			*i += 1;
		}
		else
			error_msh(WRONG_Q, msh, 2);
	}
}

void	set_dq_tok(char *line, int *i, t_token **tokens, t_msh *msh)
{
	int	start;
	int	flag;

	flag = 0;
	start = *i + 1;
	if (line[*i])
	{
		if (*i > 0 && line[*i - 1] != ' ')
			flag = 1;
		*i += 1;
		while (line[*i] && line[*i] != '\"')
			*i += 1;
		if (line[*i] == '\"')
		{
			create_tok_lst(tokens, T_DQ, ft_substr(line, start,
					(*i - start)), flag);
			*i += 1;
		}
		else
			error_msh(WRONG_DQ, msh, 2);
	}
}
