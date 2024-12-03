/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:03:41 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/03 12:07:55 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_c()
{
	static char	c = 'c';

	ft_printf("=====	ft_printf: % c	=====\n");
	ft_printf("Caractere: {%c}\n", c);
}

void	test_s()
{
	static char	*choux = "au choux.";

	ft_printf("=====	ft_printf: % s	=====\n");
	ft_printf("La soupe {%s}\n", choux);
}

int	main(void)
{
	test_c();
	ft_printf("\n");
	test_s();
	return (0);
}