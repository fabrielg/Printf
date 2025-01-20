# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 18:00:37 by gfrancoi          #+#    #+#              #
#    Updated: 2025/01/20 11:16:40 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
OPTION		= -c
NAME		= libftprintf.a

LIBFT_PATH	= ./libft/
LIBFT		= $(LIBFT_PATH)libft.a

SRCS =	ft_printf_bonus.c\
		add_char_bonus.c\
		add_str_bonus.c\
		add_nbr_bonus.c\
		add_unsigned_bonus.c\
		parsing_bonus.c

OBJS			= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

bonus: all

re: fclean all

.PHONY = all clean fclean re bonus
