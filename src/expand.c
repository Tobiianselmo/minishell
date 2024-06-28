/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:08:42 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/28 15:36:14 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_noexp_var(char *s1, int *i)
{
	char	*line;
	int		len;
	int		j;

	len = 1;
	*i += 1;
	j = *i + 1;
	while (s1[j] && s1[j] != '$' && s1[j] != '\\')
	{
		j++;
		len++;
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	j = 0;
	line[j++] = s1[*i];
	*i += 1;
	while (s1[*i] && s1[*i] != '$' && s1[*i] != '\\')
	{
		line[j++] = s1[*i];
		*i += 1;
	}
	line[j] = '\0';
	return (line);
}

void	expand_content(t_token *tok, t_env *env)
{
	int		i;
	char	*line;
	char	*aux;

	i = 0;
	line = ft_strdup("");
	while (tok->content[i])
	{
		if (tok->content[i] == '\\')
			aux = get_noexp_var(tok->content, &i);
		else if (tok->content[i] == '$')
			aux = get_exp(tok->content, &i, env);
		else
			aux = get_word(tok->content, &i);
		line = strjoin_msh(line, aux);
	}
	free(tok->content);
	tok->content = ft_strdup(line);
	free(line);
}

static void	expand_home(t_token *tok, t_env *env)
{
	int		i;
	char	*line;
	t_env	*aux;
	
	i = 0;
	line = NULL;
	aux = env;
	while (aux)
	{
		if (ft_strncmp("HOME", aux->type, 4) == 0)
			line = ft_strdup(aux->content);
		aux = aux->next;
	}
// Si el HOME no existe, tendria que guardarse el primero cuando se abrio la MINISHELL
	if (!line)
	{
		line = ft_strdup("Deberia guardar el primer HOME , en caso de no encontrar");
		/* aux = env;
		while (aux)
		{
			if (ft_strncmp("~", aux->type, 1) == 0)
				line = ft_strdup(aux->content);
		}
		aux = aux->next; */
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
		else if (tmp->exp == 2)
			expand_home(tmp, env);
		if (tmp)
			tmp = tmp->next;
	}
}
