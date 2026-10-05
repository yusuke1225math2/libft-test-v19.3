/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:25:59 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:27:44 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void	test_case(char *dst, const char *src, size_t dsize)
{
	printf("case: dst: \"%s\", src: \"%s\", dsize: %lu\n", dst, src, dsize);
	printf("strlcpy:	%lu, dst: \"%s\"\n", strlcpy(dst, src, dsize), dst);
}

void	test_case_ft(char *dst, const char *src, size_t dsize)
{
	printf("ft_strlcpy:	%lu, dst: \"%s\"\n", ft_strlcpy(dst, src, dsize), dst);
	printf("\n");
}

int	test_ft_strlcpy(void)
{
	int	fail;

	printf("===== test_ft_strlcpy =====\n");
	fail = 0;
	char	*s;

	char	d1[4] = "123";
	char	dft1[4] = "123";
	s = "ABCDE";
	test_case(d1, s, 0); 
	test_case_ft(dft1, s, 0); 

	char	d2[4] = "123";
	char	dft2[4] = "123";
	s = "ABCDE";
	test_case(d2, s, 2); 
	test_case_ft(dft2, s, 2); 

	char	d3[4] = "123";
	char	dft3[4] = "123";
	s = "ABCDE";
	test_case(d3, s, 4); 
	test_case_ft(dft3, s, 4); 

	char	d4[4] = "123";
	char	dft4[4] = "123";
	s = "ABCDE";
	test_case(d4, s, 5); 
	test_case_ft(dft4, s, 5); 

	char	d5[4] = "123";
	char	dft5[4] = "123";
	s = "ABCDE";
	test_case(d5, s, 8); 
	test_case_ft(dft5, s, 8); 
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strlcpy());
}
