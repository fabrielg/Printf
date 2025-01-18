/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 19:06:27 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conv(t_conversion conv)
{
	printf("specifier:		[%c]\n", conv.specifier);
	printf("flags:			[%d]\n", conv.flags);
	printf("field_width:		[%d]\n", conv.field_width);
	printf("precision:		[%d]\n", conv.precision);
	printf("length:			[%d]\n", conv.length);
}

void	apply_specifier_function(t_strbuilder *build, t_conversion conv, va_list args)
{
	if (conv.specifier == 'c')
		ft_putcharf(build, conv, va_arg(args, int));
	else if (conv.specifier == 's')
		ft_putstrf(build, conv, va_arg(args, char *));
	else if (conv.specifier == 'p')
		ft_putpointerf(build, conv, va_arg(args, unsigned long));
	else if (conv.specifier == 'd' || conv.specifier == 'i')
		ft_putnbrf(build, conv, va_arg(args, int));
	else if (conv.specifier == 'u')
		ft_putunsignedf(build, conv, va_arg(args, unsigned int), 0);
	else if (conv.specifier == 'x')
		ft_putunsignedf(build, conv, va_arg(args, unsigned int), 1);
	else if (conv.specifier == 'X')
		ft_putunsignedf(build, conv, va_arg(args, unsigned int), 2);
	else if (conv.specifier == '%')
		ft_putcharf(build, conv, va_arg(args, int));
}

static void	display_formatted(t_strbuilder *build, char *s, va_list args, t_conversion *conv)
{
	ft_memset(conv, 0, sizeof(t_conversion));
	if (ft_parse(s, conv))
		apply_specifier_function(build, *conv, args);
	else
		ft_sb_append(&build, s, conv->length);
}

void	ft_sprintf(t_strbuilder *build, const char *s, va_list args)
{
	char			*next_conv;
	t_conversion	conv;

	next_conv = ft_strchr(s, '%');
	while (next_conv)
	{
		ft_sb_append(&build, (char *)s, (int)(next_conv - s));
		display_formatted(build, next_conv, args, &conv);
		s += (int)(next_conv - s) + conv.length;
		next_conv = ft_strchr(s, '%');
	}
	ft_sb_append(&build, (char *)s, ft_strlen(s));
}

int	ft_printf(const char *s, ...)
{
	t_strbuilder	*build;
	va_list			args;
	int				nb_display;

	build = ft_sb_new();
	va_start(args, s);
	ft_sprintf(build, s, args);
	va_end(args);
	nb_display = ft_sb_size(build);
	ft_sb_display(build);
	ft_sb_clear(&build);
	return (nb_display);
}
