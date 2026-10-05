/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/05 23:51:41 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, int n, const char *s)
{
	int		ok;
	char	*r;

	r = ft_itoa(n);
	ok = !strcmp(r, s);
	free(r);
	return (result(name, ok));
}

int	test_ft_itoa(void)
{
	int	fail;

	printf("===== test_ft_itoa =====\n");
	fail = 0;
	fail += test_case("2147483647", 2147483647, "2147483647");
	fail += test_case("12045", 12045, "12045");
	fail += test_case("0", 0, "0");
	fail += test_case("-0", -0, "0");
	fail += test_case("-12045", -12045, "-12045");
	fail += test_case("-2147483647 - 1", -2147483647 - 1, "-2147483648");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_itoa());
}
