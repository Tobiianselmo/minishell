/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:55:57 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/27 16:57:37 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_token	*new_node(char *content, int type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->type = type;
	new->next = NULL;
	return (new);
}

/* static void	set_pipe_tok(char *line, int *i, t_token *tok)
{
	if (line[*i])
	{
		tok = new_node("|", T_PIPE);
		*i += 1;
	}
}

static void	set_g_tok(char *line, int *i, t_token *tok)
{
	if (line[*i])
	{
		if (line[*i + 1] == '<')
		{
			tok->content = ft_strdup(">>");
			tok->type = T_DG;
			*i += 2;
		}
		else
		{
			tok->content = ft_strdup(">");
			tok->type = T_G;
			*i += 1;
		}
		tok->next = NULL;
	}
}

static void	set_l_tok(char *line, int *i, t_token *tok)
{
	if (line[*i])
	{
		if (line[*i + 1] == '<')
		{
			tok = new_node("<<", T_DL);
			*i += 2;
		}
		else
		{
			tok = new_node("<", T_L);
			*i += 1;
		}
	}
	
} */

static t_token	*set_word_tok(char *line, int *i)
{
	t_token	*tok;
	int	start;

	tok = NULL;
	start = *i;
	if (line[*i])
	{
		while (line[*i] && line[*i] > 32 && line[*i] < 127 && line[*i] != '<'
				&& line[*i] != '>' && line[*i] != '|')
			*i += 1;
		tok = new_node(ft_substr(line, start, (*i - start)), T_WORD);
	}
	return (tok);
}

void	add_back(t_token **lst, t_token *new)
{
	t_token	*new_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_node = *lst;
	while (new_node->next != NULL)
		new_node = new_node->next;
	new_node->next = new;
}

void	set_tokens(char *line)
{
	int		i;
	t_token	*tokens;
	t_token	*aux;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '<' && line[i] != '>'
			&& line[i] != '|' && line[i] != '\n')
			aux = set_word_tok(line, &i);
/* 		else if (line[i] == '<')
			set_l_tok(line, &i, tokens);
		else if (line[i] == '>')
			set_g_tok(line, &i, tokens);
		else if (line[i] == '|')
			set_pipe_tok(line, &i, tokens); */
		else if (line[i] == ' ' || line[i] == '\n')
			i++;
		add_back(&tokens, )
		printf("%s\n", tokens->content);
		print_exit("llega");
	}
	print_tokens(tokens);
}

