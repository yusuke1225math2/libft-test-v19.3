/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 01:06:49 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, char *s, const char *exp)
{
	int	fds[2];

	if (pipe(fds) < 0)
		return (result(name, 0));
	ft_putendl_fd(s, fds[1]);
	return (check_output(name, fds, exp, strlen(exp)));
}

int	test_ft_putendl_fd(void)
{
	int	fail;

	printf("===== test_ft_putendl_fd =====\n");
	fail = 0;
	fail += test_case("normal", "123456", "123456\n");
	fail += test_case("empty", "", "\n");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_putendl_fd());
}
