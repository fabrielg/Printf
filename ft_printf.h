/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 20:09:14 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "./strbuilder/ft_strbuilder.h"
# include "./libft/libft.h"

# define PREFIX		0b00001 // #
# define ZERO_PAD	0b00010 // 0
# define LEFT_ALIGN	0b00100 // -
# define SPACE		0b01000 // ' '
# define SIGNED		0b10000 // +

# define FLAGS			1
# define FIELD_WIDTH	2
# define PRECISION		3
# define SPECIFIER		4

typedef struct s_specifier
{
	char	c;
	int		(*f)(va_list arg);
}	t_specifier;

typedef struct s_conversion
{
	char		specifier;
	char		flags;
	int			field_width;
	int			precision;
	int			length;
}	t_conversion;

typedef struct s_base
{
	char			*digits;
	unsigned int	size;
	char			*prefix;
}	t_base;

int		ft_printf(const char *s, ...);
int		ft_parse(const char *format, t_conversion *conv);
void	apply_specifier(t_strbuilder *build, t_conversion conv, va_list args);

void	ft_add_char(t_strbuilder *build, t_conversion conv, int c);

void	ft_add_str(t_strbuilder *build, t_conversion conv, char *s);

void	ft_add_nbr(t_strbuilder *build, t_conversion conv, int n);

void	ft_add_unsigned(t_strbuilder *build, t_conversion conv, unsigned long n, unsigned int index);

void	ft_add_pointer(t_strbuilder *build, t_conversion conv, unsigned long address);

#endif
