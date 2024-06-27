/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:31:25 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/26 15:35:25 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_token	*pop(t_token *tok)
{
	t_token	*aux;

	if (tok->next)
		aux = tok->next;
	else
		aux = NULL;
	free(tok->content);
	free(tok);
	return (aux);
}

static t_token	*join_pop(t_token *tok)
{
	t_token	*aux;
	char	*first;
	char	*next;

	aux = tok;
	first = ft_strdup(tok->content);
	next = ft_strdup(tok->next->content);
	free(aux->content);
	aux->content = ft_strjoin(first, next);
	free(first);
	free(next);
	aux->next = pop(tok->next);
	return (aux);
}

void	join_tokens(t_token **tokens)
{
	t_token	*aux;

	aux = *tokens;
	while (aux)
	{
		while ((aux->type == T_WORD || aux->type == T_Q || aux->type == T_DQ)
			&& aux->next && aux->next->flag == 1)
		{
			aux = join_pop(aux);
		}
		if (aux->type == T_Q || aux->type == T_DQ)
			aux->type = T_WORD;
		aux = aux->next;
	}
}
