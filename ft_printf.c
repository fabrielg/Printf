/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/17 19:31:17 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_specifier_function(t_conversion conv, va_list args)
{
	if (conv.specifier == 'c')
		return (ft_putchar(conv, args));
	else if (conv.specifier == 's')
		ft_putchar(conv, args);
	else if (conv.specifier == 's')
		ft_putchar(conv, args);
	else if (conv.specifier == 's')
		ft_putchar(conv, args);
	else if (conv.specifier == 's')
		ft_putchar(conv, args);
	else if (conv.specifier == 's')
		ft_putchar(conv, args);
	else if (conv.specifier == 's')
		ft_putchar(conv, args);
	else if (conv.specifier == 's')
		ft_putchar(conv, args);
	else if (conv.specifier == '%')
		ft_putchar(conv, args);
	return (0);
}

static void	printf_conv(t_conversion conv)
{
	printf("specifier:		[%c]\n", conv.specifier);
	printf("flags:			[%d]\n", conv.flags);
	printf("field_width:		[%d]\n", conv.field_width);
	printf("precision:		[%d]\n", conv.precision);
	printf("length:			[%d]\n", conv.length);
}

static int	display_formatted(char *s, va_list args)
{
	t_conversion	conv;

	ft_memset(&conv, 0, sizeof(t_conversion));
	if (ft_parse(s, &conv))
	{
		//printf_conv(conv);
		return (apply_specifier_function(conv, args));
	}
	else
	{
		return (write(1, s, conv.length));
	}
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				nb_display;
	t_conversion	conv;
	char			*next_conv;

	va_start(args, s);
	nb_display = 0;
	next_conv = ft_strchr(s, '%');
	while (next_conv)
	{
		nb_display += write(1, s, (int)(next_conv - s));
		s += (int)(next_conv - s);
		next_conv = ft_strchr(s, '%');
	}
	nb_display += write(1, s, ft_strlen(s));
	va_end(args);
	return (nb_display);
}
