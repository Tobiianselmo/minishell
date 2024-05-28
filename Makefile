# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 15:19:25 by tanselmo          #+#    #+#              #
#    Updated: 2024/05/28 19:44:14 by tanselmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER = tanselmo

LIBFT_DIR = Libft/

LIBFT = libft.a

SRCS_DIR = src

OBJ_DIR = obj

FILES = src/main.c \
src/env.c \
src/checker.c \
src/tokens.c \
src/set_tokens.c \
src/create_nodes.c \
src/prints.c \

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
#	@$(CC) $(INCLUDE) $(OBJS_SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@$(CC) $(INCLUDE) $(OBJS_SRCS) -L$(LIBFT_DIR) -lft -o $(NAME) -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

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