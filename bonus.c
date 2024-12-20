/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:32:39 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/20 14:01:29 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	tests_cs() {
	printf("[%4s] [%4s] [%.4s] [%.4s] \n", "01", "012345", "01", "012345");
	printf("[%4.4s] [%5.4s] [%-4.4s] [%-8.4s] [%.6s] [%.5s] \n", "01", "012345", "01", "012345", 0, 0);
	printf("[%c] [%c] [%4c] [%-4c] \n", '\0', 'F', 'F', 'F');
	printf("[%%] [%4%] [%.4%] [%#0-4.4%] [ %%%% %%%%%%%%%% ] \n", 0);
	printf("[%c] [%c] [%c] [%c] [%c]\n", '0', '0' - 256, 0, '1', '2');
	printf("[%c] [%c] [%c]\n", '0', 0, '1');
	printf("[%c] [%c] [%c]\n", '2', '1', 0);
	printf("[%c] [%c] [%c]\n", 0, '1', '2');
}

void	tests_d() {
	printf("[% 5d] [% 5d] [%- 5d] [%- 5d] \n", 42, -42, 42, -42);
	printf("[%+d] [%+d] [%+5d] [%+5d] \n", 10, -10, 10, -10);
	printf("[%+05d] [%+05d] [%+.5d] [%+.5d] \n", 10, -10, 10, -10);
	printf("[%-+5d] [%-+5d] \n", 10, -10);
	printf("[%04d] [%0 4d] [%0+4d] [%#4d] \n", 5, 5, 5, 5);
	printf("[%.4d] [% .4d] [%+.4d] [%#.4d] \n", 5, 5, 5, 5);
	printf("[%7.4d] [% 7.4d] [%+7.4d] [%#7.4d] \n", 5, 5, 5, 5);
	printf("[%d] [%d] [%d] [%d] [%d]\n", 0, 42, -42, 0x7FFFFFFF, 0x80000000);
	printf("[%d] [%d] [%d] [%d] [%d] [%d]\n", -1, -12, -23, -89, -90, -101);
	printf("[%d] [%d] [%d] [%d]\n", -0, -4, -9, -7);
	printf("[%.5d] [%.6d]\n", -4, -666);
	printf("[%6.4d] [%06d]\n", -42, -42);
	printf("[%1d] [%-1d] [%1.1d] [%-1.1d]\n", 0, 0, 0, 0);
	printf("[%.0d] [%.d]\n", 0, 0);
	printf("[%.4d] [%.0d]\n", 69420, 69420);
	printf("[%-10.d] [%0-10.d] [%01.0d] [%1.0d]\n", 0, 0, 0, 0);
}

void	tests_u() {
	printf("[%#010x] [%#10x] [%#.10x] [%.10x] \n", 1142, 1142, 1142, 1142);
	printf("[%#010x] [%#-10x] [%#-.10x] [%-.10x] \n", 1142, 1142, 1142, 1142);
	printf("[%#03x] [%#3x] [%#.3x] [%.3x] \n", 1142, 1142, 1142, 1142);
	printf("[%#03x] [%#-3x] [%#-.3x] [%-.3x] \n", 1142, 1142, 1142, 1142);
	printf("[%01x] [%.1x] [%06x] [%.6x]\n", 456, 456, 142, 142);
	printf("[%u] [%u] [%5u] [%.5u] [%8.4u] [%-5u] [%-8.4u]\n", 0, 0xFFFFFFFF, 42, 42, 42, 42, 42);
	printf("[%u] [%05u] [%+4u] [% 4u] [% u] [%#.4u]\n", 12, 3, 8, 24, 42, 99);
	printf("[%#8.4x] [%#-8.4x] [%#0-8.0x]\n", 17, 18, 19);
	printf("[%1u] [%1u]\n", 6, 0);

}

void	test_p() {
	char *p = "";
	printf("[%p] [%p]\n", 0, p);
	printf("[%1.1p] [%1.1p]\n", 0, p);
	printf("[%20p] [%.20p]\n", p, p);
	printf("[%-20p] [%-.20p]\n", p, p);
	printf("[%-20p] [%-.20p]\n", 0, 0);
	printf("[%20p] [%.20p]\n", 0, 0);
	printf("[%020p] [%.20p]\n", 0, 0);
}*/

#include <stdio.h>

int	main(int argc, char** argv) {
	//tests_cs();
	// printf("\n");
	// tests_d();
	// printf("\n");
	// tests_u();
	// printf("\n");
	// test_p();
	int result1;
	int result2;

	result1 = 0;
	result2 = 0;

	result1 = ft_printf("ft: [%4s] [%4s] [%.4s] [%.4s] \n", "01", "012345", "01", "012345");
	result2 = printf("pf: [%4s] [%4s] [%.4s] [%.4s] \n", "01", "012345", "01", "012345");
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%4.4s] [%5.4s] [%-4.4s] [%-8.4s] [%-8.6s] [%-8.5s] \n", "01", "012345", "01", "012345", NULL, NULL);
	result2 = printf("pf: [%4.4s] [%5.4s] [%-4.4s] [%-8.4s] [%-8.6s] [%-8.5s] \n", "01", "012345", "01", "012345", NULL, NULL);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	/*
	result1 = ft_printf("[%c] [%c] [%4c] [%-4c] \n", '\0', 'F', 'F', 'F');
	result2 = printf("[%c] [%c] [%4c] [%-4c] \n", '\0', 'F', 'F', 'F');
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("[%%] [%4%] [%.4%] [%#0-4.4%] [ %%%% %%%%%%%%%% ] \n", 0);
	result2 = printf("[%%] [%4%] [%.4%] [%#0-4.4%] [ %%%% %%%%%%%%%% ] \n", 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("[%c] [%c] [%c] [%c] [%c]\n", '0', '0' - 256, 0, '1', '2');
	result2 = printf("[%c] [%c] [%c] [%c] [%c]\n", '0', '0' - 256, 0, '1', '2');
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("[%c] [%c] [%c]\n", '0', 0, '1');
	result2 = printf("[%c] [%c] [%c]\n", '0', 0, '1');
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("[%c] [%c] [%c]\n", '2', '1', 0);
	result2 = printf("[%c] [%c] [%c]\n", '2', '1', 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("[%c] [%c] [%c]\n", 0, '1', '2');
	result2 = printf("[%c] [%c] [%c]\n", 0, '1', '2');
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	*/
}