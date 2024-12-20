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

static int	ft_get_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_putstrf(t_conversion conv, va_list args)
{
	char		*s;
	int			nb_display;
	int			precision;
	t_strbuild	*build;

	s = va_arg(args, char *);
	build = ft_strbuild_new();
	nb_display = 0;
	if (!s && conv.precision > 5)
		s = "(null)";
	else if (!s)
		s = "";
	precision = ft_get_min(conv.precision, ft_strlen(s));
	if (conv.flags & LEFT_ALIGN)
		ft_strbuild_add_front(&build, s);
	// Ajouter les caracteres ' '
	if (!(conv.flags & LEFT_ALIGN))
		ft_strbuild_add_back(&build, s);
	nb_display += ft_strbuild_display(build);
	ft_strbuild_free(&build);
	return (nb_display);
}
