/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:24:59 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/27 13:25:57 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*check_input(void)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(0);
	if (!line)
		return (NULL);
	if (!line || ft_strncmp(line, "exit", 5) == 0)
	{
		free(line);
		printf("exit\n");
	}
	return (line);
}
