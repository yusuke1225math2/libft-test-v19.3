/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:29:22 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:34:58 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#define SIGN(x) (((x) > 0) - ((x) < 0))

static int	test_case(const char *name, const char *s1, const char *s2, size_t n)
{
	return (result(name, SIGN(strncmp(s1, s2, n)) == SIGN(ft_strncmp(s1, s2, n))));
}

int	test_ft_strncmp(void)
{
	int	fail;

	printf("===== test_ft_strncmp =====\n");
	fail = 0;
	fail += test_case("\"ABC\" vs \"ABC\" n:3", "ABC", "ABC", 3);
	fail += test_case("\"ABC\" vs \"ABC\" n:5", "ABC", "ABC", 5);
	fail += test_case("\"ABC\" vs \"ABCDE\" n:6", "ABC", "ABCDE", 6);
	fail += test_case("\"ABCDEF\" vs \"ABCC\" n:6", "ABCDEF", "ABCC", 6);
	fail += test_case("\"ABCDEF\" vs \"ABCC\" n:4", "ABCDEF", "ABCC", 4);
	fail += test_case("\"ABCDEF\" vs \"ABCC\" n:3", "ABCDEF", "ABCC", 3);
	fail += test_case("\"ABCDEF\" vs \"ABCC\" n:2", "ABCDEF", "ABCC", 2);
	fail += test_case("\"ABCDEF\" vs \"ABCC\" n:0", "ABCDEF", "ABCC", 0);
	fail += test_case("\"\" vs \"ABCC\" n:4", "", "ABCC", 4);
	fail += test_case("\"ABCC\" vs \"\" n:4", "ABCC", "", 4);
	fail += test_case("\"\" vs \"ABCC\" n:2", "", "ABCC", 2);
	fail += test_case("\"\" vs \"ABCC\" n:0", "", "ABCC", 0);
	fail += test_case("\"\\x80\" vs \"\\x01\" n:1", "\x80", "\x01", 1);
	fail += test_case("\"\\x01\" vs \"\\x80\" n:1", "\x01", "\x80", 1);
	fail += test_case("\"\\xff\" vs \"\\x7f\" n:1", "\xff", "\x7f", 1);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strncmp());
}
