/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:32 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/14 15:10:45 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

static char	*ft_get_str_null(t_conversion conv)
{
	if (conv.precision >= 6 || conv.precision < 0)
		return ("(null)");
	return ("");
}

int	ft_putstrf(t_conversion conv, va_list args)
{
	t_strbuilder	*str_format;
	int				precision;
	int				nb_display;
	char			*s;

	str_format = ft_sb_new();
	s = va_arg(args, char *);
	if (!s)
		s = ft_get_str_null(conv);
	precision = ft_get_min(ft_strlen(s), conv.precision);
	if (precision < 0)
		precision = ft_strlen(s);
	if (conv.flags & LEFT_ALIGN && s)
		ft_sb_append(&str_format, s, precision);
	if (conv.field_width > precision)
		ft_sb_add_nchar(&str_format, ' ', conv.field_width - precision);
	if (!(conv.flags & LEFT_ALIGN) && s)
		ft_sb_append(&str_format, s, precision);
	ft_sb_display(str_format);
	nb_display = ft_sb_size(str_format);
	ft_sb_clear(&str_format);
	return (nb_display);
}
