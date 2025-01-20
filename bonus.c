/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:32:39 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/20 11:12:18 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	tests_cs() {
	int result1;
	int result2;

	result1 = 0;
	result2 = 0;
	
	printf("========	%%c %%s	========\n");
	result1 = ft_printf("ft: [%4s] [%4s] [%.4s] [%.4s] \n", "01", "012345", "01", "012345");
	result2 = printf("pf: [%4s] [%4s] [%.4s] [%.4s] \n", "01", "012345", "01", "012345");
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%4.4s] [%5.4s] [%-4.4s] [%-8.4s] [%-8.6s] [%-8.5s] \n", "01", "012345", "01", "012345", NULL, NULL);
	result2 = printf("pf: [%4.4s] [%5.4s] [%-4.4s] [%-8.4s] [%-8.6s] [%-8.5s] \n", "01", "012345", "01", "012345", NULL, NULL);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("ft: [%c] [%c] [%4c] [%-4c] \n", '\0', 'F', 'F', 'F');
	result2 = printf("pf: [%c] [%c] [%4c] [%-4c] \n", '\0', 'F', 'F', 'F');
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%%] [%4%] [%.4%] [%#0-4.4%] [ %%%% %%%%%%%%%% ] \n", 0);
	result2 = printf("pf: [%%] [%4%] [%.4%] [%#0-4.4%] [ %%%% %%%%%%%%%% ] \n", 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("ft: [%c] [%c] [%c] [%c] [%c]\n", '0', '0' - 256, 0, '1', '2');
	result2 = printf("pf: [%c] [%c] [%c] [%c] [%c]\n", '0', '0' - 256, 0, '1', '2');
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("ft: [%c] [%c] [%c]\n", '0', 0, '1');
	result2 = printf("pf: [%c] [%c] [%c]\n", '0', 0, '1');
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("ft: [%c] [%c] [%c]\n", '2', '1', 0);
	result2 = printf("pf: [%c] [%c] [%c]\n", '2', '1', 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("ft: [%c] [%c] [%c]\n", 0, '1', '2');
	result2 = printf("pf: [%c] [%c] [%c]\n", 0, '1', '2');
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	printf("\n");
}

void	tests_d() {
	int result1;
	int result2;

	result1 = 0;
	result2 = 0;

	printf("========	%%d %%i	========\n");
	result1 = ft_printf("ft: [% 5d] [% 5d] [%- 5d] [%- 5d] \n", 42, -42, 42, -42);
	result2 = printf("pf: [% 5d] [% 5d] [%- 5d] [%- 5d] \n", 42, -42, 42, -42);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%+d] [%+d] [%+5d] [%+5d] \n", 10, -10, 10, -10);
	result2 = printf("pf: [%+d] [%+d] [%+5d] [%+5d] \n", 10, -10, 10, -10);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%-+5d] [%-+5d] \n", 10, -10);
	result2 = printf("pf: [%-+5d] [%-+5d] \n", 10, -10);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%04d] [%0 4d] [%0+4d] [%#4d] \n", 5, 5, 5, 5);
	result2 = printf("pf: [%04d] [%0 4d] [%0+4d] [%#4d] \n", 5, 5, 5, 5);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("ft: [%.4d] [% .4d] [%+.4d] [%#.4d] \n", 5, 5, 5, 5);
	result2 = printf("pf: [%.4d] [% .4d] [%+.4d] [%#.4d] \n", 5, 5, 5, 5);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%7.4d] [% 7.4d] [%+7.4d] [%#7.4d] \n", 5, 5, 5, 5);
	result2 = printf("pf: [%7.4d] [% 7.4d] [%+7.4d] [%#7.4d] \n", 5, 5, 5, 5);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%d] [%d] [%d] [%d] [%d]\n", 0, 42, -42, 0x7FFFFFFF, 0x80000000);
	result2 = printf("pf: [%d] [%d] [%d] [%d] [%d]\n", 0, 42, -42, 0x7FFFFFFF, 0x80000000);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%d] [%d] [%d] [%d] [%d] [%d]\n", -1, -12, -23, -89, -90, -101);
	result2 = printf("pf: [%d] [%d] [%d] [%d] [%d] [%d]\n", -1, -12, -23, -89, -90, -101);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%d] [%d] [%d] [%d]\n", -0, -4, -9, -7);
	result2 = printf("pf: [%d] [%d] [%d] [%d]\n", -0, -4, -9, -7);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%.5d] [%.6d]\n", -4, -666);
	result2 = printf("pf: [%.5d] [%.6d]\n", -4, -666);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%6.4d] [%06d]\n", -42, -42);
	result2 = printf("pf: [%6.4d] [%06d]\n", -42, -42);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%1d] [%-1d] [%1.1d] [%-1.1d]\n", 0, 0, 0, 0);
	result2 = printf("pf: [%1d] [%-1d] [%1.1d] [%-1.1d]\n", 0, 0, 0, 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%.0d] [%.d]\n", 0, 0);
	result2 = printf("pf: [%.0d] [%.d]\n", 0, 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%.4d] [%.0d]\n", 69420, 69420);
	result2 = printf("pf: [%.4d] [%.0d]\n", 69420, 69420);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%-10.d] [%0-10.d] [%01.0d] [%1.0d]\n", 0, 0, 0, 0);
	result2 = printf("pf: [%-10.d] [%0-10.d] [%01.0d] [%1.0d]\n", 0, 0, 0, 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	printf("\n");
}

void	tests_u() {
	int result1;
	int result2;

	result1 = 0;
	result2 = 0;

	printf("========	%%u %%x %%X	========\n");
	result1 = ft_printf("ft: [%#010x] [%#10x] [%#.10x] [%.10x] \n", 1142, 1142, 1142, 1142);
	result2 = printf("pf: [%#010x] [%#10x] [%#.10x] [%.10x] \n", 1142, 1142, 1142, 1142);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	
	result1 = ft_printf("ft: [%#010x] [%#-10x] [%#-.10x] [%-.10x] \n", 1142, 1142, 1142, 1142);
	result2 = printf("pf: [%#010x] [%#-10x] [%#-.10x] [%-.10x] \n", 1142, 1142, 1142, 1142);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%#03x] [%#3x] [%#.3x] [%.3x] \n", 1142, 1142, 1142, 1142);
	result2 = printf("pf: [%#03x] [%#3x] [%#.3x] [%.3x] \n", 1142, 1142, 1142, 1142);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%#03x] [%#-3x] [%#-.3x] [%-.3x] \n", 1142, 1142, 1142, 1142);
	result2 = printf("pf: [%#03x] [%#-3x] [%#-.3x] [%-.3x] \n", 1142, 1142, 1142, 1142);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%01x] [%.1x] [%06x] [%.6x]\n", 456, 456, 142, 142);
	result2 = printf("pf: [%01x] [%.1x] [%06x] [%.6x]\n", 456, 456, 142, 142);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%u] [%u] [%5u] [%.5u] [%8.4u] [%-5u] [%-8.4u]\n", 0, 0xFFFFFFFF, 42, 42, 42, 42, 42);
	result2 = printf("pf: [%u] [%u] [%5u] [%.5u] [%8.4u] [%-5u] [%-8.4u]\n", 0, 0xFFFFFFFF, 42, 42, 42, 42, 42);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%u] [%05u] [%+4u] [% 4u] [% u] [%#.4u]\n", 12, 3, 8, 24, 42, 99);
	result2 = printf("pf: [%u] [%05u] [%+4u] [% 4u] [% u] [%#.4u]\n", 12, 3, 8, 24, 42, 99);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%#8.4x] [%#-8.4x] [%#0-8x]\n", 17, 18, 0);
	result2 = printf("pf: [%#8.4x] [%#-8.4x] [%#0-8x]\n", 17, 18, 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%1u] [%1u]\n", 6, 0);
	result2 = printf("pf: [%1u] [%1u]\n", 6, 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	printf("\n");
}

void	test_p() {
	int result1;
	int result2;
	char *p = "";

	printf("========	%%p	========\n");
	result1 = ft_printf("ft: [%p] [%p]\n", 0, p);
	result2 = printf("pf: [%p] [%p]\n", 0, p);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%1.1p] [%1.1p]\n", 0, p);
	result2 = printf("pf: [%1.1p] [%1.1p]\n", 0, p);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%20p] [%.20p]\n", p, p);
	result2 = printf("pf: [%20p] [%.20p]\n", p, p);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%-20p] [%-.20p]\n", p, p);
	result2 = printf("pf: [%-20p] [%-.20p]\n", p, p);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%-20p] [%-.20p]\n", 0, 0);
	result2 = printf("pf: [%-20p] [%-.20p]\n", 0, 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%20p] [%.20p]\n", 0, 0);
	result2 = printf("pf: [%20p] [%.20p]\n", 0, 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);

	result1 = ft_printf("ft: [%020p] [%.20p]\n", 0, 0);
	result2 = printf("pf: [%020p] [%.20p]\n", 0, 0);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
	printf("\n");
}

#include <stdio.h>

int	main(int argc, char** argv) {
	/*tests_cs();
	tests_d();
	tests_u();
	test_p();*/
	
	int result1;
	int result2;

	printf("========	TEST	========\n");
	result1 = ft_printf("%042.10d\n", 42000);
	result2 = printf("%042.10d\n", 42000);
	printf("result1=	%d\nresult2=	%d\n", result1, result2);
}