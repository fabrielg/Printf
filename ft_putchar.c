/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:58:27 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/17 19:19:25 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(t_conversion conv, va_list arg)
{
	int	c;
	int	nb_display;

	c = va_arg(arg, int);
	nb_display = 0;
	if (conv.flags & LEFT_ALIGN)
	{
		nb_display += write(1, &c, 1);
		while (nb_display < (conv.field_width + 1))
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
