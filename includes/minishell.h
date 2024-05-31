/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:21:09 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/31 17:52:23 by tanselmo         ###   ########.fr       */
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

typedef enum e_states
{
	S_INIT,
	S_WORD,
	S_QUOTE,
	S_DOUBLE_QUOTE,
	S_DOLLAR,
	S_DOLLAR_QUOTE
}	t_states;

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_G,
	T_L,
	T_DG,
	T_DL,
}	t_tok_type;

typedef struct s_token
{
	char			*content;
	t_tok_type		type;
	struct s_token	*next;
}	t_token;

typedef struct s_env
{
	char			*type;
	char			*content;
	struct s_env	*next;
}	t_env;

/* typedef struct s_cmd
{
	command struct
}	t_cmd; */

//-------------PRINTS-----------// (BORRAR A FUTURO)
void	print_tokens(t_token *tokens);
void	print_env(t_env *env);
void	print_exit(char *str);
//-------------INIT-------------//
void	init_msh(void);
//-------------UTILS------------//
void	error_msh(char *msg);
//--------------ENV-------------//
t_env	*get_env(char **envp);
void	get_first_env(t_env *aux, char **envp);
void	get_all_env(t_env *aux, char **envp, int y, int j);
//-------------INPUT------------//
char	*check_input(void);
//-------------TOKENS-----------//
t_token	*set_tokens(char *line);
void	set_word_tok(char *line, int *i, t_token **tokens);
void	set_dq_tok(char *line, int *i, t_token **tokens);
void	set_q_tok(char *line, int *i, t_token **tokens);
void	set_l_tok(char *line, int *i, t_token **tokens);
void	set_g_tok(char *line, int *i, t_token **tokens);
void	set_pipe_tok(char *line, int *i, t_token **tokens);
void	check_tokens(t_token **tokens);
//-----------TOKEN LIST---------//
t_token	*new_node(char *content, int type);
void	create_tok_lst(t_token **tok, int type, char *content);
void	add_back(t_token **lst, t_token *new);

#endif