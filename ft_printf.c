/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/11 12:49:11 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(char c, va_list args)
{
	static t_flag	dico[9] = {
		(t_flag){'c', ft_putchar},
		(t_flag){'s', ft_putstr},
		(t_flag){'p', ft_display_adress},
		(t_flag){'d', ft_putnbr},
		(t_flag){'i', ft_putnbr},
		(t_flag){'u', ft_putnbr_unsigned},
		(t_flag){'x', ft_puthexa},
		(t_flag){'X', ft_puthexa_upper},
		(t_flag){'%', ft_putpercent}
	};
	size_t				index;

	index = 0;
	while (index <= 9 && dico[index].c != c)
		index++;
	if (index >= 9)
	{
		write(1, "%", 1);
		write(1, &c, 1);
		return (2);
	}
	if (dico[index].f)
		return (dico[index].f(args));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		nb_display;

	va_start(args, s);
	nb_display = 0;
	while (s && *s)
	{
		if (*s == '%' && *(s + 1))
		{
			nb_display += printf_format(*(s + 1), args);
			s++;
		}
		else
		{
			nb_display += write(1, s, 1);
		}
		s++;
	}
	va_end(args);
	return (nb_display);
}
