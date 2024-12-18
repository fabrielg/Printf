/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:36:54 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 17:47:02 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(va_list arg)
{
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(arg, unsigned int);
	return (ft_putnbr_unsigned_base(nbr, "0123456789abcdef"));
}

int	ft_puthexa_upper(va_list arg)
{
	unsigned int	nbr;

	nbr = va_arg(arg, unsigned int);
	return (ft_putnbr_unsigned_base(nbr, "0123456789ABCDEF"));
}
