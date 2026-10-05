/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:51:15 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/05 23:51:16 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, !!isdigit(c) == !!ft_isdigit(c)));
}

int	test_ft_isdigit(void)
{
	int	fail;

	printf("===== test_ft_isdigit =====\n");
	fail = 0;
	fail += test_case("'/' before '0'", '/');
	fail += test_case("'0'", '0');
	fail += test_case("'9'", '9');
	fail += test_case("':' after '9'", ':');
	fail += test_case("EOF", EOF);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_isdigit());
}
