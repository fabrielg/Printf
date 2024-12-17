/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/17 17:40:12 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_specifier	*get_specifier(char c)
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
		return (NULL);
	if (dico[index].f)
		return (&(dico[index]));
	return (NULL);
}

static void	printf_conv(t_conversion conv)
{
	printf("specifier:		[%c]\n", conv.specifier.c);
	printf("flags:			[%d]\n", conv.flags);
	printf("field_width:		[%d]\n", conv.field_width);
	printf("precision:		[%d]\n", conv.precision);
	printf("length:			[%d]\n", conv.length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		nb_display;

	va_start(args, s);
	nb_display = 0;
	while (s && *s)
	{
		if (*s == '%')
		{
			t_conversion e;
			if (ft_parse(s, &e))
				printf_conv(e);
		}
		else
		{

		}
		s++;
	}
	va_end(args);
	return (nb_display);
}
