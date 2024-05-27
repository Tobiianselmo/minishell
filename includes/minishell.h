/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:21:09 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/27 15:42:09 by tanselmo         ###   ########.fr       */
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
	S_INIT = 7,
	S_WORD = 8,
	S_QUOTE = 9,
	S_DOUBLE_QUOTE = 10,
	S_DOLLAR = 11,
	S_DOLLAR_QUOTE = 12
}	t_status;

typedef enum e_token_type
{
	T_WORD = 1,
	T_PIPE = 2,
	T_G = 3,
	T_L = 4,
	T_DG = 5,
	T_DL = 6
}	t_tok_type;

typedef struct s_token
{
	char			*content;
	t_tok_type		type;
	struct	s_token	*next;
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
char	*check_input(void);
void	set_tokens(char *line);

void	print_tokens(t_token *tokens);
void	print_exit(char *str);

#endif