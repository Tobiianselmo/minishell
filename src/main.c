/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:22:29 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/10 18:25:00 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	argc = 0;
	envp = NULL;
	argv = NULL;
	while(1)
	{
		char *line = readline("minishell % ");
		if (!line || ft_strncmp(line, "exit", 5) == 0)
		{
			free(line);
			printf("exit\n");
			break ;
		}
		add_history(line);
		free(line);
		rl_on_new_line();
	}
	return (0);
}
