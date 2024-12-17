/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:36:56 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/17 17:45:26 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	check_flags(const char **format)
{
	char	flags;

	flags = 0b00000;
	while (ft_strchr("+- #0", **format))
	{
		if (**format == '#')
			flags |= PREFIX;
		else if (**format == '0')
			flags |= ZERO_PAD;
		else if (**format == '-')
			flags |= LEFT_ALIGN;
		else if (**format == ' ')
			flags |= SPACE;
		else if (**format == '+')
			flags |= SIGNED;
		(*format)++;
	}
	return (flags);
}

static int	check_field_width_precision(const char **format)
{
	int	result;

	result = -1;
	while (ft_strchr("0123456789", **format))
	{
		if (result == -1)
			result = 0;
		result = 10 * result + (**format - '0');
		(*format)++;
	}
	return (result);
}

int	ft_parse(const char *format, t_conversion *conv)
{
	if (!format || !conv)
		return (0);
	if (*(format++) != '%')
		return (0);
	conv->length = ft_strlen(format);
	conv->flags = check_flags(&format);
	conv->field_width = check_field_width_precision(&format);
	if (*format == '.')
	{
		format++;
		conv->precision = check_field_width_precision(&format);
	}
	if (ft_strchr("cspdiuxX%", *format))
	{
		conv->specifier = *(get_specifier(*format));
		return (1);
	}
	return (0);
}
