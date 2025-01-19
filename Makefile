# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 18:00:37 by gfrancoi          #+#    #+#              #
#    Updated: 2025/01/19 15:04:20 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
OPTION		= -c
NAME		= libftprintf.a

LIBFT_PATH	= ./libft/
LIBFT		= $(LIBFT_PATH)libft.a

STRBUILDER_PATH	= ./strbuilder/

SRCS =	ft_printf.c\
		ft_add_char.c\
		ft_add_str.c\
		ft_add_nbr.c\
		ft_add_unsigned.c\
		parsing.c

STRBUILDER_SRCS =	$(STRBUILDER_PATH)ft_strbuilder.c\
					$(STRBUILDER_PATH)ft_strbuilder_utils.c

OBJS			= ${SRCS:.c=.o}
STRBUILDER_OBJS	= ${STRBUILDER_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(STRBUILDER_OBJS)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJS) $(STRBUILDER_OBJS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS) $(STRBUILDER_OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

bonus: all

re: fclean all

.PHONY = all clean fclean re bonus
