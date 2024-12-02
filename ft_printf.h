/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/02 18:44:50 by gfrancoi         ###   ########.fr       */
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

int				ft_printf(const char *s, ...);

t_convention	new_convention(char format, void (*f)(va_list arg));
void			printf_format(char c, va_list args);

void			ft_putchar(va_list arg);
void			ft_putstr(va_list arg);

#endif
