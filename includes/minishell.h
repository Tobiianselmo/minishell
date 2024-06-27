/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:21:09 by tanselmo          #+#    #+#             */
/*   Updated: 2024/06/27 17:24:26 by tanselmo         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include "../Libft/libft.h"
# define RST    "\033[0m"      /* Reset to default color */
# define RED    "\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */
# define UNEXPEC_TOK "sintax error near unexpected token"
# define UNEXPEC_EOF "syntax error unexpected end of file"
# define WRONG_Q "unexpected EOF while looking for matching `''"
# define WRONG_DQ "unexpected EOF while looking for matching `\"'"
# define NO_FILE "No such file or directory"
# define NO_CFILE "File can not be created"

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
	T_Q,
	T_DQ
}	t_tok_type;

typedef struct s_token
{
	char			*content;
	t_tok_type		type;
	int				flag;
	int				exp;
	int				backslash;
	struct s_token	*next;
}	t_token;

typedef struct s_env
{
	char			*type;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	char			**argv;
	int				len;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_msh
{
	char			*line;
	int				flag;
	struct s_env	*env;
	struct s_token	*tokens;
	struct s_cmd	*cmd;
}	t_msh;

//-------------PRINTS-----------// (BORRAR A FUTURO)
void	print_tokens(t_token *tokens);
void	print_env(t_env *env);
//-------------INIT-------------//
void	init_msh(char **envp, t_msh *msh);
void	get_line(t_msh *msh);
//-------------UTILS------------//
void	error_msh(char *msg);
void	error_files(char *name, char *msg);
//--------------ENV-------------//
t_env	*get_env(char **envp);
void	get_first_env(t_env *aux, char **envp);
void	get_all_env(t_env *aux, char **envp, int y, int j);
//--------------FREE------------//
void	free_msh(t_msh *msh);
//------------DOLLAR------------//
void	expand_flag(t_token *tok);
//------------EXPAND------------//
void	expand_tokens(t_token **tokens, t_env *env);
void	expand_content(t_token *tok, t_env *env);
char	*get_exp(char *line, int *i, t_env *env);
char	*expand_var(char *var, t_env *env);
char	*get_word(char *s1, int *i);
char	*strjoin_msh(char *s1, char *s2);
//-------------JOIN-------------//
void	join_tokens(t_token **tokens);
//-------------TOKENS-----------//
t_token	*set_tokens(char *line);
void	set_word_tok(char *line, int *i, t_token **tokens);
void	set_dq_tok(char *line, int *i, t_token **tokens);
void	set_q_tok(char *line, int *i, t_token **tokens);
void	set_l_tok(char *line, int *i, t_token **tokens);
void	set_g_tok(char *line, int *i, t_token **tokens);
void	set_pipe_tok(char *line, int *i, t_token **tokens);
int		check_tokens(t_token **tokens);
//-----------TOKEN LIST--------//
t_token	*new_node(char *content, int type, int flag);
void	create_tok_lst(t_token **tok, int type, char *content, int flag);
void	add_back(t_token **lst, t_token *new);
//------------COMMANDS---------//
int		get_cmd(t_msh *msh);
//----------CMD CONTENT--------//
t_cmd	*new_node_cmd(void);
int		cmd_content(t_cmd *new, t_token *tok);
void	create_cmd_lst(t_cmd **cmd, t_cmd *new);
void	add_back_cmd(t_cmd **lst, t_cmd *new);

#endif