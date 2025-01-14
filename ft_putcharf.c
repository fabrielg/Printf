/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:59 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/14 15:14:01 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharf(t_conversion conv, va_list args)
{
	int	c;
	int	nb_display;

	c = va_arg(args, int);
	nb_display = 0;
	if (conv.flags & LEFT_ALIGN)
	{
		nb_display += write(1, &c, 1);
		while (nb_display < (conv.field_width))
			nb_display += write(1, " ", 1);
	}
	else
	{
		while (nb_display < (conv.field_width - 1))
			nb_display += write(1, " ", 1);
		nb_display += write(1, &c, 1);
	}
	return (nb_display);
}
