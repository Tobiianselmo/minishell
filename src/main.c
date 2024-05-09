/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:22:29 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/09 19:10:50 by tanselmo         ###   ########.fr       */
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
		if (ft_strncmp(line, "exit", 5) == 0)
			break;
		add_history(line);
		//printf("%s\n", line);
		rl_on_new_line();
	}
	return (0);
}
