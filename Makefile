
USER = tanselmo

LIB_RDL = -lreadline

LIBFT_DIR = Libft/

LIBFT = libft.a

SRCS_DIR = src

OBJ_DIR = obj

FILES = src/main.c \
src/init.c \
src/parser/signals.c \
src/parser/create_env_lst.c \
src/parser/tokens.c \
src/parser/set_tokens.c \
src/parser/create_nodes.c \
src/parser/errors.c \
src/parser/commands.c \
src/parser/cmd_utils.c \
src/parser/cmd_content.c \
src/parser/redirections.c \
src/parser/here_doc.c \
src/parser/here_doc_utils.c \
src/parser/free.c \
src/parser/expand.c \
src/parser/expand_flag.c \
src/parser/expand_utils.c \
src/parser/join_tokens.c \
src/parser/prints.c \
src/executor/executor.c \
src/executor/path.c \
src/executor/one_cmd.c \
src/executor/env.c \
src/executor/echo.c \
src/executor/pwd.c \
src/executor/exit.c \
src/executor/cd.c \
src/executor/export.c \
src/executor/export_utils.c \

CC = clang

CFLAGS = -g -Wall -Werror -Wextra

OBJS_SRCS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(FILES))

NAME = minishell

INCLUDE = -I $(SRCS_DIR) -I $(LIBFT_DIR)

RM = rm -rf

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#Rules

$(NAME): $(OBJS_SRCS)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	@$(CC) $(INCLUDE) $(OBJS_SRCS) $(LIB_RDL) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS):
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	@$(CC) $(INCLUDE) -L$(LIBFT_DIR) -lft -o

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re