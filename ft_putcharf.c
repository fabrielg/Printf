/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:59 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 16:47:18 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharf(t_conversion conv, int c)
{
	t_strbuilder	*str_format;
	int				nb_display;

	str_format = ft_sb_new();
	nb_display = 1;
	if (conv.specifier == 'c')
	{
		if (conv.flags & LEFT_ALIGN)
			ft_sb_add_char(&str_format, c);
		if (nb_display < (conv.field_width) && conv.field_width > 0)
			ft_sb_add_nchar(&str_format, ' ', (conv.field_width) - nb_display);
		if (!(conv.flags & LEFT_ALIGN))
			ft_sb_add_char(&str_format, c);
	}
	else
		ft_sb_add_char(&str_format, conv.specifier);
	ft_sb_display(str_format);
	nb_display = ft_sb_size(str_format);
	ft_sb_clear(&str_format);
	return (nb_display);
}
