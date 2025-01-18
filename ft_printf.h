/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:34:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/18 18:35:11 by gfrancoi         ###   ########.fr       */
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
/*
%[+- #0]	[0-9]		.[0-9]*		[cspdiuxX%]
Flags		Field_width	Precision	Conversion specifier
*/
typedef struct s_conversion
{
	char		specifier;
	char		flags;
	int			field_width;
	int			precision;
	int			length;
}	t_conversion;

typedef struct s_base {
	char			*digits;
	unsigned int	size;
	char			*prefix;
}	t_base;

/* ft_printf functions */
int		ft_printf(const char *s, ...);
int		ft_parse(const char *format, t_conversion *conv);
void	apply_specifier_function(t_strbuilder *build, t_conversion conv, va_list args);
void	printf_conv(t_conversion conv);

/* ft_putcharf functions */
void	ft_putcharf(t_strbuilder *build, t_conversion conv, int c);

/* ft_putstrf functions */
void	ft_putstrf(t_strbuilder *build, t_conversion conv, char *s);

/* ft_display_adress functions */
int		ft_display_adress(va_list arg);

/* ft_putnbr functions */
void	ft_putnbrf(t_strbuilder *build, t_conversion conv, int n);

/* ft_putnbr_unsigned functions */
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *nb_display);
int		ft_putnbr_unsigned(va_list arg);

/* ft_puthexa functions */
void	ft_putunsignedf(t_strbuilder *build, t_conversion conv, unsigned int n, unsigned int index);

/* ft_putpercent functions */
int		ft_putpercent(va_list arg);

/* utils functions */
int		ft_putnbr_unsigned_base(unsigned int nbr, char *base);
int		ft_putnbr_unsignedl_base(unsigned long nbr, char *base);

#endif
