/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:37:37 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/28 19:42:51 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_tok(int i)
{
	if (i == T_WORD)
		printf("%sTOKEN_TYPE:%s WORD", C, RST);
	else if (i == T_PIPE)
		printf("%sTOKEN_TYPE:%s PIPE", C, RST);
	else if (i == T_G)
		printf("%sTOKEN_TYPE:%s GREAT", C, RST);
	else if (i == T_L)
		printf("%sTOKEN_TYPE:%s LESS", C, RST);
	else if (i == T_DG)
		printf("%sTOKEN_TYPE:%s DOUBLE GREAT", C, RST);
	else if (i == T_DL)
		printf("%sTOKEN_TYPE:%s DOUBLE LESS", C, RST);
	else if (i == T_Q)
		printf("%sTOKEN_TYPE:%s SIMPLE QUOTE", C, RST);
	else if (i == T_DQ)
		printf("%sTOKEN_TYPE:%s DOUBLE QUOTE", C, RST);
	else
		printf("%sTOKEN_TYPE:%s NULL", C, RST);
}

void	print_tokens(t_token *tokens)
{
	printf("%sNODES%s\n", G, RST);
	while (tokens)
	{
		print_tok(tokens->type);
		printf(" %s---->%s %sTOKEN_CONTENT:%s %s\n", RED, RST, G, RST, tokens->content);
		tokens = tokens->next;
	}
}

void	print_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	print_env(t_env *env)
{
	while (env)
	{
		printf("%s%s%s=%s%s%s\n", RED, env->type, RST, W, env->content, RST);
		env = env->next;
	}
}
