/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/03 11:56:35 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_format(char c, va_list args)
{
	static t_convention	dico[9] = {
		(t_convention){'c', ft_putchar},
		(t_convention){'s', ft_putstr},
		(t_convention){'p', NULL},
		(t_convention){'d', NULL},
		(t_convention){'i', NULL},
		(t_convention){'u', NULL},
		(t_convention){'x', NULL},
		(t_convention){'X', NULL},
		(t_convention){'%', NULL}
	};
	size_t				index;

	index = 0;
	while (index <= 9 && dico[index].format != c)
		index++;
	if (index >= 9)
	{
		write(1, "%", 1);
		write(1, &c, 1);
		return ;
	}
	dico[index].f(args);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			printf_format(*(s + 1), args);
			s++;
		}
		else
		{
			write(1, s, 1);
		}
		s++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	static char	*choux = "au choux.";

	ft_printf("=====	ft_printf	=====\n");
	ft_printf("La soupe %s\n", choux);
	return (0);
}
