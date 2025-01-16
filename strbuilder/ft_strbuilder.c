/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:25:47 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/16 14:02:36 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strbuilder.h"

t_strbuilder	*ft_sb_new(void)
{
	t_strbuilder	*new;

	new = ft_calloc(1, sizeof(t_strbuilder));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->index = 0;
	return (new);
}

t_strbuilder	*ft_sb_last(t_strbuilder *sb)
{
	t_strbuilder	*last;

	last = sb;
	if (last)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}

void	ft_sb_append(t_strbuilder **sb, char *content, int size)
{
	t_strbuilder	*append;
	int				i;

	if (!sb || !*sb || !content || size < 0)
		return ;
	i = 0;
	append = ft_sb_last(*sb);
	while (i < size)
	{
		if (append->index >= (SB_SIZE - 1))
		{
			append->next = ft_sb_new();
			if (!append->next)
				break ;
			append = append->next;
		}
		append->content[append->index] = content[i];
		append->index++;
		i++;
	}
}

void	ft_sb_add_char(t_strbuilder **sb, char content)
{
	char	char_str[1];

	char_str[0] = content;
	ft_sb_append(sb, char_str, 1);
}

void	ft_sb_add_nchar(t_strbuilder **sb, char content, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < nb)
	{
		ft_sb_add_char(sb, content);
		i++;
	}
}
/*
int	main(void)
{
	t_strbuilder	*test;
	char			*str = "Je suis un test";

	test = ft_sb_new();
	ft_sb_append(&test, str, ft_strlen(str));
	ft_sb_add_char(&test, ' ');
	ft_sb_append(&test, ";)", 2);
	ft_sb_add_char(&test, ' ');
	ft_sb_add_nchar(&test, '!', 3);
	ft_sb_display(test);
	printf("\nsize: %d\n", ft_sb_size(test));
	ft_sb_debug(test);
	ft_sb_clear(&test);
}
*/
