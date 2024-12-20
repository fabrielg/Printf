/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuilder_lite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:38:05 by fabrielg          #+#    #+#             */
/*   Updated: 2024/12/20 15:03:26 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_strbuild	*ft_strbuild_new(void)
{
	t_strbuild	*new;

	new = ft_calloc(1, sizeof(t_strbuild));
	new->next = NULL;
	return (new);
}

void	ft_strbuild_add_front(t_strbuild **build, char *content)
{
	size_t		index;
	t_strbuild	*front;

	front = ft_strbuild_new();
	if (!content || !(*content) || !build || !front)
		return ;
	index = 0;
	while (*content && index < STRBUILDER_SIZE)
		front->content[index++] = (*content)++;
	front->next = *build;
	*build = front;
	if (*content)
		ft_strbuild_add_front(build, content);
}

void	ft_strbuild_add_back(t_strbuild **build, char *content)
{
	size_t		index;
	t_strbuild	*back;
	t_strbuild	*last;

	back = ft_strbuild_new();
	if (!content || !(*content) || !build || !back)
		return ;
	index = 0;
	while (*content && index < STRBUILDER_SIZE)
		back->content[index++] = (*content)++;
	last = ft_strbuild_last(*build);
	last->next = back;
	if (*content)
		ft_strbuild_add_back(build, content);
}

int	ft_strbuild_free(t_strbuild **build)
{
	if (!build || !*build)
		return (0);
	ft_strbuild_free(&(*build)->next);
	free(*build);
	*build = NULL;
	return (1);
}

t_strbuild	*ft_strbuild_last(t_strbuild *build)
{
	t_strbuild	*node;

	node = build;
	if (node)
	{
		while (node->next)
			node = node->next;
	}
	return (node);
}

size_t	ft_strbuild_size(t_strbuild *str)
{
	size_t		size;
	t_strbuild	*node;

	size = 0;
	node = str;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}
