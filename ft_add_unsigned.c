/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:36:54 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 20:11:22 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_int_base_rec(t_strbuilder *sb, unsigned long n, t_base *base)
{
	if (n >= base->size)
		ft_add_int_base_rec(sb, n / base->size, base);
	ft_sb_add_char(&sb, base->digits[n % base->size]);
}

static void	ft_add_int_base(t_strbuilder *sb, unsigned long n, int precision, t_base *base)
{
	t_strbuilder	*temp;
	int				size;

	if (!n && !precision)
		return ;
	temp = ft_sb_new();
	ft_add_int_base_rec(temp, n, base);
	size = ft_sb_size(temp);
	ft_sb_clear(&temp);
	if (precision >= 0 && precision > size)
		ft_sb_add_nchar(&sb, '0', precision - size);
	ft_add_int_base_rec(sb, n, base);
}

static int	ft_get_digits_formatted(t_conversion conv, unsigned long n, t_base base)
{
	int				result;
	t_strbuilder	*temp;

	if (!n && !conv.precision)
		return (0);
	temp = ft_sb_new();
	ft_add_int_base(temp, n, conv.precision, &base);
	result = ft_sb_size(temp);
	if (conv.flags & PREFIX && n)
		result += ft_strlen(base.prefix);
	ft_sb_clear(&temp);
	return (result);
}

void	ft_add_unsigned(t_strbuilder *build, t_conversion conv, unsigned long n, unsigned int index)
{
	static t_base	bases[] = {
	{"0123456789", 10, ""},
	{"0123456789abcdef", 16, "0x"},
	{"0123456789ABCDEF", 16, "0x"}
	};
	int				digits_formatted;
	char			fill;

	digits_formatted = ft_get_digits_formatted(conv, n, bases[index]);
	fill = ' ' + !!(conv.flags & ZERO_PAD) * ('0' - ' ') * !!digits_formatted;
	if (conv.flags & ZERO_PAD && conv.flags & PREFIX && n)
		ft_sb_append(&build, bases[index].prefix, ft_strlen(bases[index].prefix));
	if (!(conv.flags & LEFT_ALIGN) && conv.field_width > digits_formatted)
		ft_sb_add_nchar(&build, fill, conv.field_width - digits_formatted);
	if (!(conv.flags & ZERO_PAD) && conv.flags & PREFIX && n)
		ft_sb_append(&build, bases[index].prefix, ft_strlen(bases[index].prefix));
	ft_add_int_base(build, n, conv.precision, &(bases[index]));
	if (conv.flags & LEFT_ALIGN && conv.field_width > digits_formatted)
		ft_sb_add_nchar(&build, ' ', conv.field_width - digits_formatted);
}

void	ft_add_pointer(t_strbuilder *build, t_conversion conv, unsigned long address)
{
	if (address)
	{
		conv.flags |= PREFIX;
		ft_add_unsigned(build, conv, address, 1);
		return ;
	}
	if (conv.flags & LEFT_ALIGN)
		ft_sb_append(&build, "(nil)", 5);
	if (conv.field_width > 5)
		ft_sb_add_nchar(&build, ' ', conv.field_width - 5);
	if (!(conv.flags & LEFT_ALIGN))
		ft_sb_append(&build, "(nil)", 5);
}
