/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:24:00 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 18:34:15 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *nb_display)
{
	char	c;

	if (n > 9)
		ft_putnbr_unsigned_fd(n / 10, fd, nb_display);
	c = (n % 10) + '0';
	*nb_display += write(1, &c, 1);
}

int	ft_putnbr_unsigned(va_list arg)
{
	unsigned int	n;
	int				nb_display;

	n = va_arg(arg, unsigned int);
	nb_display = 0;
	ft_putnbr_unsigned_fd(n, 1, &nb_display);
	return (nb_display);
}
