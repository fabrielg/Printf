# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 18:00:37 by gfrancoi          #+#    #+#              #
#    Updated: 2024/12/05 12:48:42 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OPTION = -c
NAME = libftprintf.a

SRCS = ft_printf.c\
	ft_putcharf.c\
	ft_putstr.c\
	ft_display_adress.c\
	ft_putnbr.c\
	ft_putnbr_unsigned.c\
	ft_putnbr_unsigned_base.c\
	ft_putnbr_unsignedl_base.c\
	ft_puthexa.c\
	ft_putpercent.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $@ $?

%o: %.c
	$(CC) $(CFLAGS) $(OPTION) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
