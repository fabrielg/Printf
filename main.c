/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:03:41 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/04 15:45:25 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_c()
{
	static char	c = 'c';

	ft_printf("=====	ft_printf: % c	=====\n");
	ft_printf("ft_printf	Caractere: {%c}\n", c);
	printf("printf		Caractere: {%c}\n", c);
}

void	test_s()
{
	static char	*choux = "au choux.";

	ft_printf("=====	ft_printf: % s	=====\n");
	ft_printf("ft_printf	La soupe {%s}\n", choux);
	printf("printf		La soupe {%s}\n", choux);
}

void	test_d()
{
	static int	nbr = 42;

	ft_printf("=====	ft_printf: % d	=====\n");
	ft_printf("ft_printf	nbr = {%d}\n", nbr);
	printf("printf		nbr = {%d}\n", nbr);
}

void	test_i()
{
	static int	nbr = 42;

	ft_printf("=====	ft_printf: % i	=====\n");
	ft_printf("ft_printf	nbr = {%i}\n", nbr);
	printf("printf		nbr = {%i}\n", nbr);
}

void	test_u()
{
	static unsigned int	nbr = -20;

	ft_printf("=====	ft_printf: % u	=====\n");
	ft_printf("ft_printf	nbr = {%u}\n", nbr);
	printf("printf		nbr = {%u}\n", nbr);
}

int	main(void)
{
	test_c();
	ft_printf("\n");
	test_s();
	ft_printf("\n");
	test_d();
	ft_printf("\n");
	test_i();
	ft_printf("\n");
	test_u();
	return (0);
}