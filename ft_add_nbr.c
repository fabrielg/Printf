/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:24:00 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 20:16:34 by gfrancoi         ###   ########.fr       */
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

static int	ft_get_digits_formatted(t_conversion conv, int n)
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

static char	ft_get_sign_symbol(t_conversion conv, int n)
{
	if (n > 0 && conv.flags & SIGNED)
		return ('+');
	else if (n > 0 && conv.flags & SPACE)
		return (' ');
	return ('-');
}

static void	ft_add_int(t_strbuilder *sb, int n, t_conversion conv)
{
	char	*nbr;

	nbr = ft_itoa(n);
	if (nbr)
	{
		if (n == -2147483648)
			ft_sb_append(sb, "2147483648", 10);
		else if (n)
			ft_sb_append(sb, nbr, ft_strlen(nbr));
		else if (n == 0 && conv.precision != 0)
			ft_sb_append(sb, nbr, ft_strlen(nbr));
		free(nbr);
	}
}

void	ft_add_nbr(t_strbuilder *build, t_conversion conv, int n)
{
	char	fill;
	char	sign;
	int		digits_formatted;

	digits_formatted = ft_get_digits_formatted(conv, n);
	fill = ' ' + !!(conv.flags & ZERO_PAD) * ('0' - ' ') * !!digits_formatted;
	sign = ft_get_sign_symbol(conv, n);
	if ((conv.flags & SIGNED || conv.flags & SPACE || n < 0) && conv.flags & ZERO_PAD)
		ft_sb_add_char(build, sign);
	if (!(conv.flags & LEFT_ALIGN) && conv.field_width > digits_formatted)
		ft_sb_add_nchar(build, fill, conv.field_width - digits_formatted);
	if ((conv.flags & SIGNED || conv.flags & SPACE || n < 0) && !(conv.flags & ZERO_PAD))
		ft_sb_add_char(build, sign);
	if (conv.precision >= 0 && conv.precision > ft_nb_digits(n))
		ft_sb_add_nchar(build, '0', conv.precision - ft_nb_digits(n));
	if (n < 0)
		n = (unsigned int)-n;
	ft_add_int(build, n, conv);
	if (conv.flags & LEFT_ALIGN && conv.field_width > digits_formatted)
		ft_sb_add_nchar(build, fill, conv.field_width - digits_formatted);
}
