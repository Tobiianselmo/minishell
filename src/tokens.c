/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:55:57 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/07 14:10:57 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_pipe_tok(char *line, int *i, t_token **tokens)
{
	if (line[*i])
	{
		create_tok_lst(tokens, T_PIPE, ft_strdup("|"));
		*i += 1;
	}
}

void	set_g_tok(char *line, int *i, t_token **tokens)
{
	if (line[*i])
	{
		if (line[*i + 1] == '>')
		{
			create_tok_lst(tokens, T_DG, ft_strdup(">>"));
			*i += 2;
		}
		else
		{
			create_tok_lst(tokens, T_G, ft_strdup(">"));
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
			create_tok_lst(tokens, T_DL, ft_strdup("<<"));
			*i += 2;
		}
		else
		{
			create_tok_lst(tokens, T_L, ft_strdup("<"));
			*i += 1;
		}
	}
}

void	set_q_tok(char *line, int *i, t_token **tokens)
{
	int	start;

	start = *i + 1;
	if (line[*i])
	{
		*i += 1;
		while (line[*i] && line[*i] != '\'')
			*i += 1;
		if (line[*i] == '\'')
		{
			create_tok_lst(tokens, T_WORD, ft_substr(line, start, (*i - start)));
			*i += 1;	
		}
		else
		{
			error_msh(WRONG_Q);
		}
	}
}

void	set_dq_tok(char *line, int *i, t_token **tokens)
{
	int	start;

	start = *i;
	if (line[*i])
	{
		*i += 1;
		while (line[*i] && line[*i] != '\"')
			*i += 1;
		if (line[*i] == '\"')
		{
			create_tok_lst(tokens, T_WORD, ft_substr(line, start, (*i - start)));
			*i += 1;	
		}
		else
		{
			error_msh(WRONG_DQ);
		}
	}
}
