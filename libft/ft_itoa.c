/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:50:15 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 12:52:58 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_digits(int n)
{
	int	result;

	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	result = 1;
	while (n >= 10)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char		*result;
	long int	nbr;
	int			digits;

	nbr = n;
	digits = ft_nb_digits(nbr);
	if (n < 0)
	{
		nbr *= -1;
		printf("TEST/ %ld\n", nbr);
		digits++;
	}
	result = ft_calloc((digits + 1), sizeof(char));
	if (!result)
		return (NULL);
	result[digits] = 0;
	while (digits--)
	{
		result[digits] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
