#include "../../includes/minishell.h"

static void	new_var_value(t_msh *msh, char *str)
{
	char	*var;
	char	*content;
	int		i;
	int		start;

	i = 0;
	while (str[i] != '=')
		i++;
	var = ft_substr(str, 0, i);
	start = ++i;
	while (str[i])
		i++;
	content = ft_substr(str, start, (i - start));
	if (!var || !content)
		return ;
	set_env(msh, var, content);
	free(var);
	free(content);
}

static void	add_var_value(t_msh *msh, char *str)
{
	char	*var;
	char	*new_content;
	char	*content;
	int		start;
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	var = ft_substr(str, 0, (i - 1));
	start = ++i;
	while (str[i])
		i++;
	content = ft_substr(str, start, (i - start));
	if (!var || !content)
		return ;
	if (get_env(msh, var))
		new_content = ft_strjoin(get_env(msh, var), content);
	else
		new_content = ft_strjoin("", content);
	set_env(msh, var, new_content);
	return(free(var), free(content), free(new_content));
}

static int	add_vars(t_msh *msh)
{
	int	i;
	int	j;

	i = 1;
	while (msh->cmd->argv[i])
	{
		j = 0;
		if (!ft_strchr(msh->cmd->argv[i], '='))
		{
			if (get_env(msh, msh->cmd->argv[i]))
			{
				i++;
				continue ;
			}
			add_env(msh, msh->cmd->argv[i], NULL);
		}
		while (msh->cmd->argv[i][j])
		{
			if (msh->cmd->argv[i][j] == '+')
			{
				add_var_value(msh, msh->cmd->argv[i]);
				break ;
			}
			if (msh->cmd->argv[i][j] == '=')
			{
				new_var_value(msh, msh->cmd->argv[i]);
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	export(t_msh *msh)
{
	if (!msh->cmd->argv[1])
		print_export(msh->env);
	else
	{
		if (add_vars(msh))
			printf("error\n");
	}
}
