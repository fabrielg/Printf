/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_adress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:15:16 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 18:57:20 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_adress(va_list arg)
{
	void	*p;
	int		nb_display;

	p = va_arg(arg, void *);
	nb_display = 0;
	if (!p)
		nb_display += write(1, "(nil)", 5);
	else
	{
		nb_display += write(1, "0x", 2);
		nb_display += ft_putnbr_unsigned_base(*(int *)p, "0123456789abcdef");
	}
	return (nb_display);
}
