/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:25:59 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 20:39:45 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

#define BUF_SIZE 8

static int	test_case(const char *name, const char *src, size_t size)
{
	char	da[BUF_SIZE];
	char	db[BUF_SIZE];
	size_t	ra;
	size_t	rb;
	int		ok;

	assert(size <= BUF_SIZE);
	memset(da, 'x', BUF_SIZE);
	memset(db, 'x', BUF_SIZE);
	ra = strlcpy(da, src, size);
	rb = ft_strlcpy(db, src, size);
	ok = (ra == rb) && (memcmp(da, db, BUF_SIZE) == 0);
	return (result(name, ok));
}

int	test_ft_strlcpy(void)
{
	int	fail;

	printf("===== test_ft_strlcpy =====\n");
	fail = 0;
	fail += test_case("size 0", "ABCDE", 0);
	fail += test_case("size 1", "ABCDE", 1);
	fail += test_case("size 2", "ABCDE", 2);
	fail += test_case("size 4", "ABCDE", 4);
	fail += test_case("size 5(==len)", "ABCDE", 5);
	fail += test_case("size 6(==len+1)", "ABCDE", 6);
	fail += test_case("size 7", "ABCDE", 7);
	fail += test_case("size 8", "ABCDE", 8);
	fail += test_case("empty src, size 0", "", 0);
	fail += test_case("empty src, size 1", "", 1);
	fail += test_case("empty src, size 8", "", 8);
	fail += test_case("1-char src, size 2", "Z", 2);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strlcpy());
}
