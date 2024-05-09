# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 18:54:17 by tanselmo          #+#    #+#              #
#    Updated: 2024/03/27 12:17:48 by tanselmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFILES = ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_toupper.c \
ft_tolower.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c
CFILES_BONUS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c
CFILES_PRINTF = ft_printf.c \
ft_putchar_pf.c \
ft_putstr_pf.c \
ft_putnbr_pf.c \
ft_putnbr_u_pf.c \
ft_hexa_pf.c \
ft_hexaup_pf.c \
ft_hexapointer_pf.c
CFILES_GNL = get_next_line_bonus.c \
get_next_line_utils_bonus.c \

OFILES = $(CFILES:.c=.o)

OFILES_BONUS = $(CFILES_BONUS:.c=.o)

OFILES_PRINTF = $(CFILES_PRINTF:.c=.o)

OFILES_GNL = $(CFILES_GNL:.c=.o)

NAME = libft.a

#rules
all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

bonus:	$(OFILES_BONUS)
		ar rcs $(NAME) $(OFILES_BONUS)

printf:	$(OFILES_PRINTF)
		ar rcs $(NAME) $(OFILES_PRINTF)

gnl: $(OFILES_GNL)
		ar rcs $(NAME) $(OFILES_GNL)

clean:
	rm -f $(OFILES) $(OFILES_BONUS) $(OFILES_PRINTF) $(OFILES_GNL)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)