/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:55:12 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:08:41 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#define SIGN(x) (((x) > 0) - ((x) < 0))

static int	test_case(const char *name, const void *s1, const void *s2,
						size_t n)
{
	int	ra;
	int	rb;

	ra = memcmp(s1, s2, n);
	rb = ft_memcmp(s1, s2, n);
	return (result(name, SIGN(ra) == SIGN(rb)));
}

static int	test_buffers(void)
{
	int	a[] = {1, 2, 3};
	int	b[] = {1, 2, 2};
	int	fail;

	fail = 0;
	fail += test_case("int arr 0", a, b, 0);
	fail += test_case("int arr same", a, b, 2);
	fail += test_case("int arr diff", a, b, 3);
	return (fail);
}

int	test_ft_memcmp(void)
{
	int	fail;

	printf("===== test_ft_memcmp =====\n");
	fail = 0;
	fail += test_case("equal", "abc", "abc", 3);
	fail += test_case("differs 1st", "abc", "xbc", 3);
	fail += test_case("differs last", "abc", "abd", 3);
	fail += test_case("reversed", "abd", "abc", 3);
	fail += test_case("n==0", "abc", "xyz", 0);
	fail += test_case("differs after n", "abcde", "abcDE", 3);
	fail += test_case("differs at n - 1", "abcde", "aBcde", 2);
	fail += test_case("no NUL stopping", "a\0b", "a\0c", 3);
	fail += test_case("no nul stopping", "\0\0", "\0\0", 2);
	fail += test_case("high bytes vs low", "\x80", "\x01", 1);
	fail += test_case("reversed", "\x01", "\x80", 1);
	fail += test_case("extremes", "\xff", "\x00", 1);
	fail += test_buffers();
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_memcmp());
}
