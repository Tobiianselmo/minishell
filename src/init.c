/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:38:09 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/05 21:11:45 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_msh(void)
{
	char		*line;
	t_token		*tok;
	t_cmd		*cmd;

	cmd = NULL;
	line = ft_strdup("ls -la | wc -l");
	add_history(line);
	tok = set_tokens(line);
	check_tokens(&tok);
/* 	cmd = get_cmd(tok);
	int i;
	while (cmd)
	{
		i = 0;
		printf("COMANDO: %s\n", cmd->cmd);
		while (cmd->argv[i])
			printf("MATRIX CMD: %s\n", cmd->argv[i++]);
		cmd = cmd->next;
	} */
	print_tokens(tok);
}
