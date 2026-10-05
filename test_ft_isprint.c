/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:51:26 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/05 23:51:27 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, !!isprint(c) == !!ft_isprint(c)));
}

int	test_ft_isprint(void)
{
	int	fail;

	printf("===== test_ft_isprint =====\n");
	fail = 0;
	fail += test_case("'31'", 31);
	fail += test_case("' '", ' ');
	fail += test_case("'&'", '&');
	fail += test_case("'~'", '~');
	fail += test_case("'127'", 127);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	test_ft_isprint();
}
