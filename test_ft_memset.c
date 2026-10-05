/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:31:59 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:42:58 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case_char(const char *name, int c, size_t n)
{
	char	sa[6] = "12345";
	char	sb[6] = "12345";
	void	*rb;
	int		ok;

	memset(sa, c, n);
	rb = ft_memset(sb, c, n);
	ok = (memcmp(sa, sb, sizeof(sa)) == 0)
		&& rb == sb;
	return (result(name, ok));
}

static int	test_case_int(const char *name, int c, size_t n)
{
	int		sa[6] = {1, 2, 3, 4, 5, 6};
	int		sb[6] = {1, 2, 3, 4, 5, 6};
	void	*rb;
	int		ok;

	memset(sa, c, n);
	rb = ft_memset(sb, c, n);
	ok = (memcmp(sa, sb, sizeof(sa)) == 0)
		&& rb == sb;
	return (result(name, ok));
}

int	test_ft_memset(void)
{
	int	fail;

	printf("===== test_ft_memset =====\n");
	fail = 0;
	fail += test_case_int("int 1 3", 1, 3);
	fail += test_case_int("int 1 0", 1, 0);
	fail += test_case_int("int -1 3", -1, 3);
	fail += test_case_char("char 'A' 3", 'A', 3);
	fail += test_case_char("char 'A' 0", 'A', 0);
	fail += test_case_char("char -1 3", -1, 3);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_memset());
}
