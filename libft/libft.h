/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:41:14 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/19 15:24:49 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef UL
#  define UL unsigned long
# endif

# ifndef UI
#  define UI unsigned int
# endif

/* ft_strlen.c */
size_t	ft_strlen(const char *s);

/* ft_putchar_fd.c */
void	ft_putchar_fd(char c, int fd);

/* ft_putstr_fd.c */
int		ft_putstr_fd(char *str, int fd);
int		ft_putstrn_fd(char *str, int n, int fd);

/* ft_putnbr_fd.c */
void	ft_putnbr_fd(int n, int fd);

/* ft_strchr.c */
char	*ft_strchr(const char *s, int c);

/* ft_calloc.c */
void	*ft_calloc(size_t nmemb, size_t size);

/* ft_bzero.c */
void	ft_bzero(void *s, size_t n);

/* ft_memset.c */
void	*ft_memset(void *s, int c, size_t n);

/* ft_memcpy.c */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* ft_nb_digits.c */
int		ft_nb_digits(int n);

/* ft_itoa.c */
char	*ft_itoa(int n);

#endif
