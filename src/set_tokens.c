/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:21:29 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/07 14:05:17 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_tokens(t_token **tokens)
{
	t_token	*aux;
	int		flag;

	aux = *tokens;
	flag = 0;
	while (aux)
	{
		if (aux->type == T_PIPE && !flag)
			return (error_msh(UNEXPEC_TOK), 0);
		else if (aux->type == T_L || aux->type == T_G || aux->type == T_DL
			|| aux->type == T_DG || aux->type == T_PIPE)
		{
			if (!aux->next)
				return (error_msh(UNEXPEC_EOF), 0);
			if (aux->next->type != T_WORD)
				return (error_msh(UNEXPEC_TOK), 0);
		}
		aux = aux->next;
		flag++;
	}
	return (1);
}

void	set_word_tok(char *line, int *i, t_token **tokens)
{
	int		start;

	start = *i;
	if (line[*i])
	{
		while (line[*i] && line[*i] > 32 && line[*i] < 127 && line[*i] != '<'
			&& line[*i] != '>' && line[*i] != '|'
			&& line[*i] != '\'' && line[*i] != '\"')
			*i += 1;
		create_tok_lst(tokens, T_WORD, ft_substr(line, start, (*i - start)));
	}
}

t_token	*set_tokens(char *line)
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
			set_q_tok(line, &i, &tokens);
		else if (line[i] == '\"')
			set_dq_tok(line, &i, &tokens);
		else if (line[i] == ' ' || line[i] == '\n')
			i++;
	}
	return (tokens);
}
