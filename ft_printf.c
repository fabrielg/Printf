/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:36 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/02 18:43:01 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_convention	new_convention(char format, void (*f)(va_list arg))
{
	t_convention	new;

	new.format = format;
	new.f = f;
	return (new);
}

void	printf_format(char c, va_list args)
{
	t_convention	dico[9] = {
		new_convention('c', ft_putchar),
		new_convention('s', ft_putstr)
	};
	size_t	index;

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
	char	*choux = "au choux.";

	ft_printf("=====	ft_printf	=====\n");
	ft_printf("La soupe %s\n", choux);
	return (0);
}
