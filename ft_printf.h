/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 16:17:58 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_conversion
{
	char	format;
	void	(*f)(va_list arg);
}	t_convention;

/* ft_printf functions */
void	printf_format(char c, va_list args);
int		ft_printf(const char *s, ...);

/* ft_putchar functions */
void	ft_putchar(va_list arg);

/* ft_putstr functions */
void	ft_putstr(va_list arg);

/* ft_putnbr functions */
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(va_list arg);

/* ft_putnbr_unsigned functions */
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr_unsigned(va_list arg);

/* ft_putpercent functions */
void	ft_putpercent(va_list arg);

#endif
