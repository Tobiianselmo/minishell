#include "../includes/minishell.h"

static void	set_backslash_tok(char *line, int *i, t_token **tokens, int flag)
{
	int	start;

	start = *i + 1;
	if (line[*i] == '\\' && line[*i + 1] != '\0')
	{
		if (line[*i + 1] == '$' || line[*i + 1] == '~')
			start--;
		*i += 1;
		if (line[*i + 1] && line[*i + 1] == '~')
			*i += 1;
		create_tok_lst(tokens, T_WORD, ft_substr(line, start,
				(*i + 1 - start)), flag);
	}
	else
		create_tok_lst(tokens, T_WORD, ft_strdup(""), 2);
	*i += 1;
}

void	set_word_tok(char *line, int *i, t_token **tokens)
{
	int	start;
	int	flag;
	int	j;

	flag = 0;
	start = *i;
	j = 0;
	if (line[*i])
	{
		if (*i > 0 && line[*i - 1] != ' ')
			flag = 1;
		if (*i > 1 && line[*i - 1] != ' ' && line[*i - 2] == '\\')
			flag = 1;
		if (line[*i] == '\\')
			set_backslash_tok(line, i, tokens, flag);
		else
		{
			while (line[*i] && line[*i] > 32 && line[*i] < 127
				&& line[*i] != '<' && line[*i] != '>' && line[*i] != '|'
				&& line[*i] != '\'' && line[*i] != '\"' && line[*i] != '\\')
				*i += 1;
			create_tok_lst(tokens, T_WORD, ft_substr(line, start,
					(*i - start)), flag);
		}
	}
}

t_token	*set_tokens(char *line, t_msh *msh)
{
	int		i;
	t_token	*tokens;

	i = 0;
	tokens = NULL;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '<' && line[i] != '>'
			&& line[i] != '|' && line[i] != '\n' && line[i] != '\''
			&& line[i] != '\"')
			set_word_tok(line, &i, &tokens);
		else if (line[i] == '<')
			set_l_tok(line, &i, &tokens);
		else if (line[i] == '>')
			set_g_tok(line, &i, &tokens);
		else if (line[i] == '|')
			set_pipe_tok(line, &i, &tokens);
		else if (line[i] == '\'')
			set_q_tok(line, &i, &tokens, msh);
		else if (line[i] == '\"')
			set_dq_tok(line, &i, &tokens, msh);
		else if (line[i] == ' ' || line[i] == '\n')
			i++;
	}
	return (tokens);
}

int	check_tokens(t_token **tokens, t_msh *msh)
{
	t_token	*aux;
	int		flag;

	aux = *tokens;
	flag = 0;
	while (aux)
	{
		if (!flag++ && aux->type == T_PIPE)
			return (error_msh(UNEXPEC_TOK, msh, 2), 0);
		else if (aux->type != T_WORD && aux->type != T_Q && aux->type != T_DQ)
		{
			if (!aux->next)
				return (error_msh(UNEXPEC_EOF, msh, 2), 0);
			if (aux->next->type != T_WORD && aux->next->type != T_Q
				&& aux->next->type != T_DQ)
				return (error_msh(UNEXPEC_TOK, msh, 127), 0);
		}
		else if (aux->type == T_WORD)
		{
			if (!aux->next && aux->flag == 2)
				return (error_msh(UNEXPEC_EOF, msh, 2), 0);
		}
		aux = aux->next;
	}
	return (1);
}
