/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:49:14 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 22:39:11 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case_int(const char *name, size_t n)
{
	int	sa[5] = {1, 2, 3, 4, 5};
	int	sb[5] = {1, 2, 3, 4, 5};

	bzero(sa, n);
	ft_bzero(sb, n);
	return (result(name, memcmp(sa, sb, sizeof(sa)) == 0));
}

static int	test_case_char(const char *name, size_t n)
{
	char	sa[5] = "abcd";
	char	sb[5] = "abcd";

	bzero(sa, n);
	ft_bzero(sb, n);
	return (result(name, memcmp(sa, sb, sizeof(sa)) == 0));
}

int	test_ft_bzero(void)
{
	int	fail;

	fail = 0;
	printf("===== test_ft_bzero =====\n");
	fail += test_case_int("int  n:0", 0);
	fail += test_case_int("int  n:5", 5);
	fail += test_case_char("char  n:0", 0);
	fail += test_case_char("char  n:5", 5);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_bzero());
}
