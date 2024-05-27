/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:37:37 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/27 15:43:37 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_tok(int i)
{
	if (i == 1)
		printf("%sTOKEN_TYPE:%s WORD", C, RST);
	else if (i == 2)
		printf("%sTOKEN_TYPE:%s PIPE", C, RST);
	else if (i == 3)
		printf("%sTOKEN_TYPE:%s >", C, RST);
	else if (i == 4)
		printf("%sTOKEN_TYPE:%s <", C, RST);
	else if (i == 5)
		printf("%sTOKEN_TYPE:%s >>", C, RST);
	else if (i == 6)
		printf("%sTOKEN_TYPE:%s <<", C, RST);
}

void	print_tokens(t_token *tokens)
{
	printf("%sNODES%s\n", G, RST);
	while (tokens)
	{
		print_tok(tokens->type);
		printf("\n");
		printf("%sTOKEN_CONTENT:%s %s\n", C, RST, tokens->content);
		tokens = tokens->next;
	}
}

void	print_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}
