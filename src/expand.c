/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:08:42 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/19 18:49:41 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*strjoin_msh(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		a;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	a = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	while (s1[i])
		ret[a++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[a++] = s2[i++];
	ret[a++] = '\0';
	free(s1);
	free(s2);
	return (ret);
}

static char	*get_word(char *s1, int *i)
{
	char	*line;
	int		len;
	int		j;

	len = 0;
	j = *i;
	while (s1[j] && s1[j] != '$')
	{
		j++;
		len++;
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (s1[*i] && s1[*i] != '$')
	{
		line[j++] = s1[*i];
		*i += 1;
	}
	line[j] = '\0';
	return (line);
}

static char *expand_var(char *var, t_env *env)
{
	t_env	*aux;
	char	*line;
	int		len;

	aux = env;
	line = ft_strdup("");
	while (aux)
	{
		len = ft_strlen(aux->type);
		if (ft_strncmp(var, aux->type, len) == 0 && var[len] == '\0')
		{
			free(line);
			line = ft_strdup(aux->content);
			break ;
		}
		aux = aux->next;
	}
	return (line);
}

static char	*get_exp(char *line, int *i, t_env *env)
{
	char	*ret;
	char	*var;
	int		start;

	start = *i + 1;
	*i += 1;
	while (line[*i] && line[*i] != '$' && line[*i] != '|'
		&& line[*i] != '<' && line[*i] != '>' && line[*i] != ' ')
		*i += 1;
	var = ft_substr(line, start, (*i - start));
	ret = expand_var(var, env);
	free(var);
	return (ret);
}

static void	expand_content(t_token *tok, t_env *env)
{
	int		i;
	char	*line;
	char	*aux;

	i = 0;
	line = ft_strdup("");
	while (tok->content[i])
	{
		if (tok->content[i] == '$')
		{
			aux = get_exp(tok->content, &i, env); //buscar la variable a expandir y retornarla
		}
		else
			aux = get_word(tok->content, &i); //hacer un join hasta un $ o el nulo
		line = strjoin_msh(line, aux); //liberar line y aux dentro del join
	}
	free(tok->content);
	tok->content = ft_strdup(line);
	free(line);
}

void	expand_tokens(t_token **tokens, t_env *env)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		if (tmp->type == T_DL)
			tmp = tmp->next;
		else if (tmp->exp == 1)
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

