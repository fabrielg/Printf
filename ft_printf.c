/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/18 12:56:29 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_conv(t_conversion conv)
{
	printf("specifier:		[%c]\n", conv.specifier);
	printf("flags:			[%d]\n", conv.flags);
	printf("field_width:		[%d]\n", conv.field_width);
	printf("precision:		[%d]\n", conv.precision);
	printf("length:			[%d]\n", conv.length);
}

int	apply_specifier_function(t_conversion conv, va_list args)
{
	if (conv.specifier == 'c')
		return (ft_putcharf(conv, args));
	else if (conv.specifier == 's')
		ft_putcharf(conv, args);
	else if (conv.specifier == 'p')
		ft_putcharf(conv, args);
	else if (conv.specifier == 'd' || conv.specifier == 'i')
		ft_putcharf(conv, args);
	else if (conv.specifier == 'u')
		ft_putcharf(conv, args);
	else if (conv.specifier == 'x')
		ft_putcharf(conv, args);
	else if (conv.specifier == 'X')
		ft_putcharf(conv, args);
	else if (conv.specifier == '%')
		ft_putcharf(conv, args);
	return (0);
}

static int	display_formatted(char *s, va_list args, t_conversion *conv)
{
	ft_memset(conv, 0, sizeof(t_conversion));
	if (ft_parse(s, conv))
	{
		// printf("\noui\n");
		// printf_conv(*conv);
		return (apply_specifier_function(*conv, args));
	}
	else
	{
		// printf("\nnon\n");
		// printf_conv(*conv);
		return (write(1, s, conv->length));
	}
}

int	ft_sprintf(const char *s, va_list args)
{
	int		nb_display;
	char	*next_conv;
	t_conversion	conv;

	nb_display = 0;
	next_conv = ft_strchr(s, '%');
	while (next_conv)
	{
		nb_display += write(1, s, (int)(next_conv - s));
		nb_display += display_formatted(next_conv, args, &conv);
		s += (int)(next_conv - s) + conv.length;
		next_conv = ft_strchr(s, '%');
	}
	nb_display += write(1, s, ft_strlen(s));
	return (nb_display);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		nb_display;
	
	va_start(args, s);
	nb_display = ft_sprintf(s, args);
	va_end(args);
	return (nb_display);
}
