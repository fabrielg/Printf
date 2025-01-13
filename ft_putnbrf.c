/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:24:00 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/13 20:06:26 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrf_fd(int n, int fd, int *nb_display)
{
	char	c;

	if (n == -2147483648)
		*nb_display += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			*nb_display += write(1, "-", 1);
			n *= -1;
		}
		if (n > 9)
			ft_putnbrf_fd(n / 10, fd, nb_display);
		c = (n % 10) + '0';
		*nb_display += write(1, &c, 1);
	}
}

int	ft_putnbrf(va_list arg)
{
	int	n;
	int	nb_display;

	n = va_arg(arg, int);
	nb_display = 0;
	ft_putnbrf_fd(n, 1, &nb_display);
	return (nb_display);
}
