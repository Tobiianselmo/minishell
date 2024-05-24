/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:21:09 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/24 17:31:34 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../Libft/libft.h"
# define RST    "\033[0m"      /* Reset to default color */
# define RED    "\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

typedef enum e_status
{
	S_INIT = 1,
	S_WORD = 2,
	S_QUOTE = 3,
	S_DOUBLE_QUOTE = 4,
	S_DOLLAR = 5,
	S_DOLLAR_QUOTE = 6
}	t_status;

typedef enum e_token_type
{
	T_START = 1,
	T_WORD = 2,
	T_PIPE = 3,
	T_G = 4,
	T_L = 5,
	T_DG = 6,
	T_DL = 7
}	t_tok_type;

typedef struct s_token
{
	char	*content;

}	t_token;

typedef struct s_env
{
	char			*type;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	/*command struct*/
}	t_cmd;

t_env	*get_env(char **envp);
void	get_first_env(t_env *aux, char **envp);
void	get_all_env(t_env *aux, char **envp, int y, int j);
void	print_env(t_env *env);

#endif