/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/11 12:50:57 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	char	c;
	int		(*f)(va_list arg);
}	t_flag;

typedef struct s_conversion
{
	t_flag	flag;
	char	*format;
	int		format_size;
}	t_conversion;

/* ft_printf functions */
int		printf_format(char c, va_list args);
int		ft_printf(const char *s, ...);

/* ft_putchar functions */
int		ft_putchar(va_list arg);

/* ft_putstr functions */
int		ft_putstr(va_list arg);

/* ft_display_adress functions */
int		ft_display_adress(va_list arg);

/* ft_putnbr functions */
void	ft_putnbr_fd(int n, int fd, int *nb_display);
int		ft_putnbr(va_list arg);

/* ft_putnbr_unsigned functions */
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *nb_display);
int		ft_putnbr_unsigned(va_list arg);

/* ft_puthexa functions */
int		ft_puthexa(va_list arg);
int		ft_puthexa_upper(va_list arg);

/* ft_putpercent functions */
int		ft_putpercent(va_list arg);

/* utils functions */
int		ft_putnbr_unsigned_base(unsigned int nbr, char *base);
int		ft_putnbr_unsignedl_base(unsigned long nbr, char *base);

#endif
