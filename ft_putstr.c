/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:00:01 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 18:56:04 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list arg)
{
	char	*s;
	int		nb_display;

	s = va_arg(arg, char *);
	if (!s)
		return (write(1, "(null)", 6));
	nb_display = 0;
	while (*s)
		nb_display += write(1, s++, 1);
	return (nb_display);
}
