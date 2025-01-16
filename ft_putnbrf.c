/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:24:00 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/16 15:10:22 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nb_digits(int n)
{
	int	result;

	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	result = 1;
	while (n >= 10)
	{
		n /= 10;
		result++;
	}
	return (result);
}

int	ft_get_digits_formatted(t_conversion conv, int n)
{
	int	result;

	result = ft_nb_digits(n);
	if (conv.precision > result)
		result += (conv.precision - result);
	if (n < 0)
		result++;
	else
	{
		if (conv.flags & SIGNED)
			result++;
		else if (conv.flags & SPACE)
			result++;
	}
	return (result);
}

int	ft_putnbrf(t_conversion conv, va_list args)
{
	int	n;
	int	nb_display;
	char	fill;
	int	digits_formatted;
	t_strbuilder	*sb;

	n = va_arg(args, int);
	digits_formatted = ft_get_digits_formatted(conv, n);
	//printf_conv(conv);
	sb = ft_sb_new();
	fill = ' ' + !!(conv.flags & ZERO_PAD) * ('0' - ' ');
	if (!(conv.flags & LEFT_ALIGN) && conv.field_width > digits_formatted)
		ft_sb_add_nchar(&sb, fill, conv.field_width - digits_formatted);
	// + et ' '
	if (conv.flags & SIGNED && n >= 0)
		ft_sb_add_char(&sb, '+');
	else if (conv.flags & SPACE && n >= 0)
		ft_sb_add_char(&sb, ' ');
	// Precision
	if (conv.precision >= 0 && conv.precision > ft_nb_digits(n))
		ft_sb_add_nchar(&sb, '0', conv.precision - ft_nb_digits(n));
	// putnbr n
	ft_sb_append(&sb, ft_itoa(n), ft_strlen(ft_itoa(n)));
	if (conv.flags & LEFT_ALIGN && conv.field_width > digits_formatted)
		ft_sb_add_nchar(&sb, fill, conv.field_width - digits_formatted);
	nb_display = 0;
	nb_display = ft_sb_size(sb);
	ft_sb_display(sb);
	ft_sb_clear(&sb);
	return (nb_display);
}
