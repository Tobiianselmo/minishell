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
	return (free(var), free(content), free(new_content));
}

static void	add_vars(t_msh *msh, int i)
{
	int	j;

	j = 0;
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
}

static int	parse_export(t_msh *msh, char *line)
{
	int	i;

	i = 0;
	if (!ft_isalpha(line[i]) && line[i] != '_')
		return (error_msh(EXPORT, msh, 1), 0);
	while (line[i])
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
		{
			if (line[i] != '+' && line[i] != '=')
				return (error_msh(EXPORT, msh, 1), 0);
			if (line[i] == '+' && line[i + 1] && line[i + 1] != '=')
				return (error_msh(EXPORT, msh, 1), 0);
		}
		i++;
	}
	return (1);
}

void	export(t_msh *msh)
{
	int	i;

	i = 0;
	if (!msh->cmd->argv[1])
		print_export(msh->env);
	else
	{
		while (msh->cmd->argv[++i])
		{
			if (parse_export(msh, msh->cmd->argv[i]))
			{
				if (!ft_strchr(msh->cmd->argv[i], '='))
				{
					if (get_env(msh, msh->cmd->argv[i]))
						continue ;
					add_env(msh, msh->cmd->argv[i], NULL);
				}
				else
					add_vars(msh, i);
			}
		}
	}
}
