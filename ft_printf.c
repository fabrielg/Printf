/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/15 22:42:43 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flags(char *s)
{
	int	res;

	res = 0b00000;
	if (ft_strchr(s, '#'))
		res |= PREFIX;
	if (ft_strchr(s, '0'))
		res |= ZERO_PAD;
	if (ft_strchr(s, '-'))
		res |= LEFT_ALIGN;
	if (ft_strchr(s, ' '))
		res |= SPACE;
	if (ft_strchr(s, '+'))
		res |= SIGNED;
	return (res);
}

t_conversion	*parsing(char *s)
{
	t_conversion	conv;
	char			flags;

	flags = parse_flags(s);
	if ((flags | LEFT_ALIGN) && (flags | ZERO_PAD))
		flags &= ZERO_PAD;
	if ((flags | LEFT_ALIGN) && (flags | ZERO_PAD))
		flags &= ZERO_PAD;
	return (&conv);
}

int	printf_format(char c, va_list args)
{
	static t_specifier	dico[9] = {
		(t_specifier){'c', ft_putchar},
		(t_specifier){'s', ft_putstr},
		(t_specifier){'p', ft_display_adress},
		(t_specifier){'d', ft_putnbr},
		(t_specifier){'i', ft_putnbr},
		(t_specifier){'u', ft_putnbr_unsigned},
		(t_specifier){'x', ft_puthexa},
		(t_specifier){'X', ft_puthexa_upper},
		(t_specifier){'%', ft_putpercent}
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
	char	*temp;
	int		nb_display;

	va_start(args, s);
	nb_display = 0;
	while (s && *s)
	{
		if (*s == '%' && *(s + 1))
		{
			temp = ft_strchr("cspdiuxX%", s);
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
