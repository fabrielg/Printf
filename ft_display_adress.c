/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_adress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:15:16 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 17:19:41 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_adress(va_list arg)
{
	void	*p;

	p = va_arg(arg, void *);
	if (!p)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		ft_putnbr_unsigned_base(p, "0123456789abcdef");
	}
}
