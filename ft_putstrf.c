/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:00:01 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 18:56:04 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrf(t_conversion conv, va_list args)
{
	char	*s;
	int		nb_display;

	s = va_arg(args, char *);
	nb_display = 0;

	if (!s)
	{
		if (!s && conv.precision > 5)
			nb_display += write(1, "(null)", 6);
		while (s && *s && nb_display < conv.field_width)
			nb_display += write(1, s++, 1);
		while (nb_display < conv.field_width)
			nb_display += write(1, " ", 1);
	}


	if (conv.flags & LEFT_ALIGN)
	{
	}
	else
	{
		if (!s && conv.precision > 5)
			nb_display += write(1, "(null)", 6);
		while (s && *s && nb_display < conv.field_width)
			nb_display += write(1, s++, 1);
		while (nb_display < conv.field_width)
			nb_display += write(1, " ", 1);
	}
	return (nb_display);
}
