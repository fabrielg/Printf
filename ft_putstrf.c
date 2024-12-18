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
	char		*s;
	int			nb_display;
	t_strbuild	*str;

	s = va_arg(args, char *);
	str = ft_strbuild_new('c');
	nb_display = 0;

	return (nb_display);
}
