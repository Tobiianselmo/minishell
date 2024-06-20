/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:43:06 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/20 15:30:53 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*strjoin_msh(char *s1, char *s2)
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

char	*get_word(char *s1, int *i)
{
	char	*line;
	int		len;
	int		j;

	len = 0;
	j = *i;
	while (s1[j] && s1[j] != '$' && s1[j] != '\\')
	{
		j++;
		len++;
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (s1[*i] && s1[*i] != '$' && s1[*i] != '\\')
	{
		line[j++] = s1[*i];
		*i += 1;
	}
	line[j] = '\0';
	return (line);
}

char	*expand_var(char *var, t_env *env)
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

char	*get_exp(char *line, int *i, t_env *env)
{
	char	*ret;
	char	*var;
	int		start;

	start = *i + 1;
	*i += 1;
	while (line[*i] && line[*i] != '$' && line[*i] != '|'
		&& line[*i] != '<' && line[*i] != '>' && line[*i] != ' '
		&& line[*i] != '\\')
		*i += 1;
	var = ft_substr(line, start, (*i - start));
	ret = expand_var(var, env);
	free(var);
	return (ret);
}
