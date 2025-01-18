/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:24:00 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 13:31:19 by gfrancoi         ###   ########.fr       */
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

	if (!n && !conv.precision)
		return (0);
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

char	ft_get_sign_symbol(t_conversion conv, int n)
{
	if (n > 0 && conv.flags & SIGNED)
		return ('+');
	else if (n > 0 && conv.flags & SPACE)
		return (' ');
	return ('-');
}

void	ft_add_int(t_strbuilder *sb, int n, t_conversion conv)
{
	if (n == -2147483648)
		ft_sb_append(&sb, "2147483648", 10);
	else if (n)
		ft_sb_append(&sb, ft_itoa(n), ft_strlen(ft_itoa(n)));
	else if (n == 0 && conv.precision != 0)
		ft_sb_append(&sb, ft_itoa(n), ft_strlen(ft_itoa(n)));
}

int	ft_putnbrf(t_conversion conv, va_list args)
{
	int				n;
	int				nb_display;
	char			fill;
	char			sign;
	int				digits_formatted;
	t_strbuilder	*sb;

	n = va_arg(args, int);
	digits_formatted = ft_get_digits_formatted(conv, n);
	sb = ft_sb_new();
	fill = ' ' + !!(conv.flags & ZERO_PAD) * ('0' - ' ') * !!digits_formatted;
	sign = ft_get_sign_symbol(conv, n);
	if ((conv.flags & SIGNED || conv.flags & SPACE || n < 0) && conv.flags & ZERO_PAD)
		ft_sb_add_char(&sb, sign);
	if (!(conv.flags & LEFT_ALIGN) && conv.field_width > digits_formatted)
		ft_sb_add_nchar(&sb, fill, conv.field_width - digits_formatted);
	if ((conv.flags & SIGNED || conv.flags & SPACE || n < 0) && !(conv.flags & ZERO_PAD))
		ft_sb_add_char(&sb, sign);
	if (conv.precision >= 0 && conv.precision > ft_nb_digits(n))
		ft_sb_add_nchar(&sb, '0', conv.precision - ft_nb_digits(n));
	if (n < 0)
		n = (unsigned int)-n;
	ft_add_int(sb, n, conv);
	if (conv.flags & LEFT_ALIGN && conv.field_width > digits_formatted)
		ft_sb_add_nchar(&sb, fill, conv.field_width - digits_formatted);
	nb_display = 0;
	nb_display = ft_sb_size(sb);
	ft_sb_display(sb);
	ft_sb_clear(&sb);
	return (nb_display);
}
