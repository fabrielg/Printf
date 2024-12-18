/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuilder_lite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabrielg <fabrielg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:38:05 by fabrielg          #+#    #+#             */
/*   Updated: 2024/12/18 17:56:15 by fabrielg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_strbuild	*ft_strbuild_new(char content)
{
	t_strbuild	new;

	new.c = content;
	new.next = NULL;
	return (&new);
}

t_strbuild	*ft_strbuild_last(t_strbuild *str)
{
	t_strbuild	*node;

	node = str;
	if (node)
	{
		while (node->next)
			node = node->next;
	}
	return (node);
}

size_t	ft_strbuild_size(t_strbuild *str)
{
	size_t	size;

	size = 0;
	while (str)
	{
		str = str->next;
		size++;
	}
	return (size);
}

void	ft_strbuild_add_front(t_strbuild *str, char content)
{
	t_strbuild	*front;

	front = strbuild_new(content);
	front->next = str;
	str->next = front;
}

void	ft_strbuild_add_back(t_strbuild *str, char content)
{
	t_strbuild	*back;

	back = strbuild_new(content);
	if (!str)
		str = back;
	else
	{
		back = ft_strbuild_last(str);
		str->next = back;
	}
}