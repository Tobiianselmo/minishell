/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:38:09 by tanselmo          #+#    #+#             */
/*   Updated: 2024/07/02 12:49:33 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	printf("%sCOMMANDS%s\n", RED, RST);
	while (cmd)
	{
		i = 0;
		printf("%s%s%s\n", C, cmd->argv[0], RST);
		while (cmd->argv[i])
		{
			printf("%sCONTENT:%s %s\n", G, RST, cmd->argv[i++]);
		}
		printf("%sERROR: %s%d\n", M, RST, cmd->error);
		printf("%sFD_IN = %s%d\n", M, RST, cmd->fd_in);
		printf("%sFD_OUT = %s%d\n", M, RST, cmd->fd_out);
		cmd = cmd->next;
	}
}

static int	clean_tokens(t_msh *msh)
{
	expand_flag(msh->tokens);
	expand_tokens(&msh->tokens, msh);
	join_tokens(&msh->tokens);
	if (check_tokens(&msh->tokens, msh))
		return (1);
	return (0);
}

void	init_msh(char **envp, t_msh *msh)
{
	msh->env = get_env(envp);
	msh->cmd_len = 0;
	msh->state = 0;
	msh->cmd = NULL;
	msh->tokens = NULL;
}

void	get_line(t_msh *msh)
{
	msh->line = readline(W"Min"RST RED"ish"RST W"ell% "RST);
	while (msh->line)
	{
		add_history(msh->line);
		if (msh->line[0] == '\0')
			free(msh->line);
		else
		{
			msh->tokens = set_tokens(msh->line, msh);
			if (clean_tokens(msh))
			{
				get_cmd(msh);
				print_cmd(msh->cmd);
			}
			free_msh(msh);
		}
		msh->line = readline(W"Min"RST RED"ish"RST W"ell% "RST);
	}
}
