/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:58:48 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 01:02:37 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, char *s)
{
	int	fds[2];

	if (pipe(fds) < 0)
		return (result(name, 0));
	ft_putstr_fd(s, fds[1]);
	return (check_output(name, fds, s, strlen(s)));
}

int	test_ft_putstr_fd(void)
{
	int	fail;

	printf("===== test_ft_putstr_fd =====\n");
	fail = 0;
	fail += test_case("normal", "ABCDEF");
	fail += test_case("empty", "");
	fail += test_case("stops at NUL", "AB\0CD");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_putstr_fd());
}
