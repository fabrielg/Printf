# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 20:30:12 by gfrancoi          #+#    #+#              #
#    Updated: 2025/01/20 11:15:27 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OPTION = -c
NAME = libft.a

SRCS =	ft_strlen.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c\
		ft_strchr.c\
		ft_calloc.c\
		ft_bzero.c\
		ft_memset.c\
		ft_memcpy.c\
		ft_nb_digits.c\
		ft_itoa.c\
		ft_strbuilder.c\
		ft_strbuilder_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $@ $?

%.o: %.c
	$(CC) $(CFLAGS) $(OPTION) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
