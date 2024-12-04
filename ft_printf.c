/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 15:44:51 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_format(char c, va_list args)
{
	static t_convention	dico[9] = {
		(t_convention){'c', ft_putchar},
		(t_convention){'s', ft_putstr},
		(t_convention){'p', NULL},
		(t_convention){'d', ft_putnbr},
		(t_convention){'i', ft_putnbr},
		(t_convention){'u', ft_putnbr_unsigned},
		(t_convention){'x', NULL},
		(t_convention){'X', NULL},
		(t_convention){'%', NULL}
	};
	size_t				index;

	index = 0;
	while (index <= 9 && dico[index].format != c)
		index++;
	if (index >= 9)
	{
		write(1, "%", 1);
		write(1, &c, 1);
		return ;
	}
	if (dico[index].f)
		dico[index].f(args);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			printf_format(*(s + 1), args);
			s++;
		}
		else
		{
			write(1, s, 1);
		}
		s++;
	}
	va_end(args);
	return (0);
}
