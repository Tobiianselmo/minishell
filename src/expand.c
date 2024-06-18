/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:08:42 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/18 18:05:47 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*return_char(char c)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(sizeof(char) * 2);
	if (!line)
		return (NULL);
	line[i++] = c;
	line[i] = '\0';
	return (line);
}

static char	*join_expand(char *line, )
{
	/* hacer mañana miercoleh333333333333333333333 */
}
static void	expand_content(t_token *tok, char **env)
{
	int		i;
	char	*line;
	char	*aux;

	i = 0;
	line = ft_strdup("");
	while (tok->content[i])
	{
		if (tok->content[i] == '$')
			aux = join_exp(tok->content, &i, env);
		else
		{
			aux = return_char(tok->content[i]); //hacer un strdup de un char solo
			i++;
		}
		line = strjoin_msh(line, aux); //liberar line y aux dentro del join
	}
	free(tok->content);
	tok->content = ft_strdup(line);
	free(line);
}

void	expand_tokens(t_token **tokens, t_env *env)
{
	t_token	*tmp;
	char	*content;

	tmp = *tokens;
	while (tmp)
	{
		if ((tmp->type == T_WORD || tmp->type == T_DQ)
			&& tmp->exp == 1)
			expand_content(tmp, env);
		tmp = tmp->next;
	}
}

/* PASO A PASO

1ro deberia ir recorriendo los tokens hasta encontrar un 
word o double quote y que contenga la flag de expandir en 1

2do  */

/* Deberia comenzar a leer la line con la expansion y luego ir buscando
cada variable de entorno a ver si se puede expandir o no, mientras voy 
encontrando la idea seria ir armando una linea la cual es la que voy a
asignarle a content en ese tok

POR EJEMPLO: TOK->CONTENT = "$USER hola $HOME"

La idea seria ir buscando cada variable de entorno y ir joineandola a
un array el cual termine conteniendo tanselmo hola /home/tanselmo */

