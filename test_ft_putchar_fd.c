/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:58:23 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 00:59:47 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, char c)
{
	int	fds[2];

	if (pipe(fds) < 0)
		return (result(name, 0));
	ft_putchar_fd(c, fds[1]);
	return (check_output(name, fds, &c, 1));
}

int	test_ft_putchar_fd(void)
{
	int	fail;

	printf("===== test_ft_putchar_fd =====\n");
	fail = 0;
	fail += test_case("'a'", 'a');
	fail += test_case("'\\n'", '\n');
	fail += test_case("'\\0'", '\0');
	fail += test_case("0xff", (char)0xff);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_putchar_fd());
}
