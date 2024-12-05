/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:03:41 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/05 12:58:55 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_c()
{
	static char	c = 'c';

	ft_printf("=====	ft_printf: %%c	=====\n");
	ft_printf("ft_printf	Caractere: {%c}\n", c);
	printf("printf		Caractere: {%c}\n", c);
}

void	test_s()
{
	static char	*choux = NULL;

	ft_printf("=====	ft_printf: %%s	=====\n");
	ft_printf("ft_printf	La soupe {%s}\n", choux);
	printf("printf		La soupe {%s}\n", choux);
}

void	test_p()
{
	static int	p = -3342;

	ft_printf("=====	ft_printf: %%p	=====\n");
	ft_printf("ft_printf	Adresse de p = {%d} {%p}\n", p, p);
	printf("printf		Adresse de p = {%d} {%p}\n", p, p);
}

void	test_d()
{
	static int	nbr = 42;

	ft_printf("=====	ft_printf: %%d	=====\n");
	ft_printf("ft_printf	nbr = {%d}\n", nbr);
	printf("printf		nbr = {%d}\n", nbr);
}

void	test_i()
{
	static int	nbr = 42;

	ft_printf("=====	ft_printf: %%i	=====\n");
	ft_printf("ft_printf	nbr = {%i}\n", nbr);
	printf("printf		nbr = {%i}\n", nbr);
}

void	test_u()
{
	static unsigned int	nbr = -20;

	ft_printf("=====	ft_printf: %%u	=====\n");
	ft_printf("ft_printf	nbr = {%u}\n", nbr);
	printf("printf		nbr = {%u}\n", nbr);
}

void	test_x()
{
	static int	nbr = -255;

	ft_printf("=====	ft_printf: %%x	=====\n");
	ft_printf("ft_printf	nbr = %d, in hexa = {%x}\n", nbr, nbr);
	printf("printf		nbr = %d, in hexa = {%x}\n", nbr, nbr);
}

void	test_X()
{
	static int	nbr = -255;

	ft_printf("=====	ft_printf: %%X	=====\n");
	ft_printf("ft_printf	nbr = %d, in HEXA = {%X}\n", nbr, nbr);
	printf("printf		nbr = %d, in HEXA = {%X}\n", nbr, nbr);
}

void	test_percent()
{
	ft_printf("=====	ft_printf: %%%	=====\n");
	ft_printf("ft_printf	voici un pourcent : {%%}\n");
	printf("printf		voici un pourcent : {%%}\n");
}

int	main(void)
{
	test_c();
	ft_printf("\n");
	test_s();
	ft_printf("\n");
	test_p();
	ft_printf("\n");
	test_d();
	ft_printf("\n");
	test_i();
	ft_printf("\n");
	test_u();
	ft_printf("\n");
	test_x();
	ft_printf("\n");
	test_X();
	ft_printf("\n");
	test_percent();
	return (0);
}
