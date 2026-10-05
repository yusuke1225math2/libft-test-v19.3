/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:31:59 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/05 23:39:35 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case_char(const char *name, int c, size_t n)
{
	char	sa[6] = "12345";
	char	sb[6] = "12345";

	memset(sa, c, n);
	ft_memset(sb, c, n);
	return (result(name, memcmp(sa, sb, 6) == 0));
}

static int	test_case_int(const char *name, int c, size_t n)
{
	int	sa[6] = {1, 2, 3, 4, 5, 6};
	int	sb[6] = {1, 2, 3, 4, 5, 6};

	memset(sa, c, n);
	ft_memset(sb, c, n);
	return (result(name, memcmp(sa, sb, 6) == 0));
}

int	test_ft_memset(void)
{
	int	fail = 0;

	printf("===== test_ft_memset =====\n");
	fail += test_case_int("int 1 3", 1, 3);
	fail += test_case_int("int 1 0", 1, 0);
	fail += test_case_char("char 'A' 3", 'A', 3);
	fail += test_case_char("char 'A' 0", 'A', 0);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_memset());
}
