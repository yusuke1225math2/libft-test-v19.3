/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:58:42 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 01:11:58 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, int n)
{
	int		fds[2];
	char	exp[16];
	int		len;

	if (pipe(fds) < 0)
		return (result(name, 0));
	ft_putnbr_fd(n, fds[1]);
	len = snprintf(exp, sizeof(exp), "%d", n);
	return (check_output(name, fds, exp, len));
}

int	test_ft_putnbr_fd(void)
{
	int	fail;

	printf("===== test_ft_putnbr_fd =====\n");
	fail = 0;
	fail += test_case("0", 0);
	fail += test_case("9", 9);
	fail += test_case("10", 10);
	fail += test_case("-1", -1);
	fail += test_case("123456", 123456);
	fail += test_case("-123456", -123456);
	fail += test_case("INT_MAX", INT_MAX);
	fail += test_case("INT_MIN", INT_MIN);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_putnbr_fd());
}
