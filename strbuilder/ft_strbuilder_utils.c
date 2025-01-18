/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuilder_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:54:11 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 20:10:37 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strbuilder.h"

int	ft_sb_display(t_strbuilder *sb)
{
	char	*build;
	int		index;
	int		nb_display;

	build = ft_calloc(ft_sb_size(sb), sizeof(char) + 1);
	if (!build)
		return (-1);
	index = 0;
	while (sb)
	{
		ft_memcpy((build + index), sb->content, sb->index + 1);
		index += sb->index;
		sb = sb->next;
	}
	nb_display = ft_putstrn_fd(build, index, 1);
	free(build);
	return (nb_display);
}

int	ft_sb_size(t_strbuilder *sb)
{
	int	size;

	size = 0;
	if (sb)
	{
		size += SB_SIZE;
		while (sb->next)
		{
			size += SB_SIZE;
			sb = sb->next;
		}
		size -= (SB_SIZE - sb->index);
	}
	return (size);
}

int	ft_sb_clear(t_strbuilder **sb)
{
	if (!*sb || !sb)
		return (0);
	ft_sb_clear(&(*sb)->next);
	free(*sb);
	*sb = NULL;
	return (1);
}
