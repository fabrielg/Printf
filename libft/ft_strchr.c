/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:54:22 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/17 17:42:28 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	if (!c)
		return (NULL);
	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *) &s[i]);
}
