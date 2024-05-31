/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:38:09 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/31 17:57:43 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_msh(void)
{
	char	*line;
	t_token	*tok;

	line = ft_strdup("ls| echo 'hola' > > out ");
	tok = set_tokens(line);
	check_tokens(&tok);
	print_tokens(tok);
}
