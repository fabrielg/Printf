/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuilder_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:54:11 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/14 13:04:58 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strbuilder.h"

void	ft_sb_debug(t_strbuilder *sb)
{
	while (sb)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("content: [", 1);
		ft_putstr_fd(sb->content, 1);
		ft_putstr_fd("]\nnext: [", 1);
		if (sb->next)
			ft_putstr_fd(sb->next->content, 1);
		else
			ft_putstr_fd("(null)", 1);
		ft_putstr_fd("]\nindex: ", 1);
		ft_putnbr_fd(sb->index, 1);
		ft_putstr_fd("\n", 1);
		sb = sb->next;
	}
}

void	ft_sb_display(t_strbuilder *sb)
{
	while (sb)
	{
		ft_putstr_fd(sb->content, 1);
		sb = sb->next;
	}
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
		size -= (SB_SIZE - ft_strlen(sb->content));
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
