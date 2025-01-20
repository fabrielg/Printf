# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 18:00:37 by gfrancoi          #+#    #+#              #
#    Updated: 2025/01/20 12:46:39 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
OPTION		= -c
NAME		= libftprintf.a
MANDA_PATH	= ./manda/
BONUS_PATH	= ./bonus/

LIBFT_PATH	= ./libft/
LIBFT		= $(LIBFT_PATH)libft.a

INCLUDES =	-I$(LIBFT_PATH) \
				-I$(MANDA_PATH)\
				-I$(BONUS_PATH)

SRCS_MANDA = $(MANDA_PATH)ft_printf.c\
		$(MANDA_PATH)add_char.c\
		$(MANDA_PATH)add_str.c\
		$(MANDA_PATH)add_nbr.c\
		$(MANDA_PATH)add_unsigned.c\
		$(MANDA_PATH)parsing.c

SRCS_BONUS = $(BONUS_PATH)ft_printf_bonus.c\
		$(BONUS_PATH)add_char_bonus.c\
		$(BONUS_PATH)add_str_bonus.c\
		$(BONUS_PATH)add_nbr_bonus.c\
		$(BONUS_PATH)add_unsigned_bonus.c\
		$(BONUS_PATH)parsing_bonus.c

MANDA_OBJS	= ${SRCS_MANDA:.c=.o}
BONUS_OBJS	= ${SRCS_BONUS:.c=.o}

# MANDA PART
all: $(NAME)

$(NAME): $(LIBFT) $(MANDA_OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(MANDA_OBJS)

$(MANDA_PATH)%.o: $(MANDA_PATH)%.c
	$(CC) $(CFLAGS) $(INCLUDES) $(OPTION) $< -o $@
# END MANDA PART

# BONUS PART
bonus: $(LIBFT) $(BONUS_OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(BONUS_OBJS)

$(BONUS_PATH)%.o: $(BONUS_PATH)%.c
	$(CC) $(CFLAGS) $(INCLUDES) $(OPTION) $< -o $@
# END BONUS PART

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(MANDA_OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY = all clean fclean re bonus
