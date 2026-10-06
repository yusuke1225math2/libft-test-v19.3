/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:33:35 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 01:41:11 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, tolower(c) == ft_tolower(c)));
}

int	test_ft_tolower(void)
{
	int	fail = 0;

	printf("===== test_ft_tolower =====\n");
	fail += test_case("\' \'", ' ');
	fail += test_case("\'0\'", '0');
	fail += test_case("\'a\'", 'a');
	fail += test_case("\'A\'", 'A');
	fail += test_case("\'Z\'", 'Z');
	fail += test_case("before 'A'", '@');
	fail += test_case("after 'Z'", '[');
	fail += test_case("before 'a'", '`');
	fail += test_case("after 'z'", '{');
	fail += test_case("EOF", EOF);
	fail += test_case("128", 128);
	fail += test_case("255", 255);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_tolower());
}
