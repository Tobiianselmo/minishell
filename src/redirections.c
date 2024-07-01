/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:25:13 by tanselmo          #+#    #+#             */
/*   Updated: 2024/07/01 10:25:41 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_outfile(t_token **tok, t_cmd *new)
{
	*tok = (*tok)->next;
	if (new->error == 0)
	{
		if (new->fd_out > 2)
			close(new->fd_out);
		new->fd_out = open((*tok)->content,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (new->fd_out == -1)
		{
			error_files((*tok)->content, NO_CFILE);
			new->error = 1;
		}
	}
	*tok = (*tok)->next;
}

void	set_append(t_token **tok, t_cmd *new)
{
	*tok = (*tok)->next;
	if (new->error == 0)
	{	
		if (new->fd_out > 2)
			close(new->fd_out);
		new->fd_out = open((*tok)->content,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (new->fd_out == -1)
		{
			error_files((*tok)->content, NO_CFILE);
			new->error = 1;
		}
	}
	*tok = (*tok)->next;
}

void	set_infile(t_token **tok, t_cmd *new)
{
	*tok = (*tok)->next;
	if (new->fd_in > 2)
		close(new->fd_in);
	new->fd_in = open((*tok)->content, O_RDONLY);
	if (new->fd_in == -1)
	{
		error_files((*tok)->content, NO_FILE);
		new->error = 1;
	}
	*tok = (*tok)->next;
}
