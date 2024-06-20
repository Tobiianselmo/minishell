/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:03:48 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/20 12:40:45 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_first_env(t_env *aux, char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (envp[0])
	{
		while (envp[0][i] != '=')
			i++;
		aux->type = ft_substr(envp[0], 0, i);
		j = ++i;
		while (envp[0][j])
			j++;
		aux->content = ft_substr(envp[0], i, (j - i));
		aux->next = NULL;
	}
}

void	get_all_env(t_env *aux, char **envp, int y, int j)
{
	int	x;

	while (envp[++y])
	{
		x = 0;
		aux->next = malloc(sizeof(t_env));
		if (!aux)
			return ;
		aux = aux->next;
		while (envp[y][x] != '=')
			x++;
		aux->type = ft_substr(envp[y], 0, x);
		j = ++x;
		while (envp[y][j])
			j++;
		aux->content = ft_substr(envp[y], x, (j - x));
		aux->next = NULL;
	}
}

t_env	*get_env(char **envp)
{
	t_env	*env;
	t_env	*aux;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	aux = env;
	get_first_env(aux, envp);
	get_all_env(aux, envp, 0, 0);
	return (env);
}
