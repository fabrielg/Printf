/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_adress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:15:16 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/05 12:53:12 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_adress(va_list arg)
{
	unsigned long	address;
	int				nb_display;

	address = va_arg(arg, unsigned long);
	nb_display = 0;
	if (!address)
		nb_display += write(1, "(nil)", 5);
	else
	{
		nb_display += write(1, "0x", 2);
		nb_display += ft_putnbr_unsignedl_base(address, "0123456789abcdef");
	}
	return (nb_display);
}
