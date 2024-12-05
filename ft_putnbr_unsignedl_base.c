/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsignedl_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:46:18 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/05 12:56:50 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	all_unique_char(char *str)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_base_string_correct(char *base, int size)
{
	int	i;

	if (size <= 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(('A' <= base[i] && base[i] <= 'Z') \
		|| ('a' <= base[i] && base[i] <= 'z') \
		|| ('0' <= base[i] && base[i] <= '9')))
			return (0);
		i++;
	}
	return (all_unique_char(base));
}

static void	print_decimal_to_base(unsigned long d, char *b, int sz, int *n)
{
	if (d >= (unsigned long)sz)
	{
		print_decimal_to_base(d / sz, b, sz, n);
		print_decimal_to_base(d % sz, b, sz, n);
	}
	else
		*n += write(1, &b[d], 1);
}

int	ft_putnbr_unsignedl_base(unsigned long nbr, char *base)
{
	int		i;
	int		size;
	int		nb_display;

	i = 0;
	size = ft_strlen(base);
	nb_display = 0;
	if (is_base_string_correct(base, size))
	{
		print_decimal_to_base(nbr, base, size, &nb_display);
	}
	return (nb_display);
}
