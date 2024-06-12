/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:55:51 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/12 19:10:03 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_dollar(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	dollar_flag(t_token *tok)
{
	t_token	*aux;

	aux = tok;
	while (aux)
	{
		aux->exp = 0;
		if (aux->type == T_WORD || aux->type == T_DQ)
		{
			if (check_dollar(aux->content) == 1)
				aux->exp = 1;
		}
		aux = aux->next;
	}
}
