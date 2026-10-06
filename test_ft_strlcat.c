/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:19:37 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 21:38:24 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

#define BUF_SIZE 10

static int	test_case(const char *name, const char *init, const char *src,
						size_t size)
{
	char	da[BUF_SIZE];
	char	db[BUF_SIZE];
	size_t	ra;
	size_t	rb;
	int		ok;

	assert(size <= BUF_SIZE);
	memcpy(da, init, BUF_SIZE);
	memcpy(db, init, BUF_SIZE);
	ra = strlcat(da, src, size);
	rb = ft_strlcat(db, src, size);
	ok = (ra == rb) && (memcmp(da, db, BUF_SIZE) == 0);
	return (result(name, ok));
}

int	test_ft_strlcat(void)
{
	int			fail;
	const char	*d3 = "123\0xxxxxx";
	const char	*d0 = "\0xxxxxxxxx";
	const char	*dn = "xxxxxxxxxx";

	printf("===== test_ft_strlcat =====\n");
	fail = 0;
	fail += test_case("dst 3: size 0", d3, "ABCDE", 0);
	fail += test_case("dst 3: size 2 (< dlen)", d3, "ABCDE", 2);
	fail += test_case("dst 3: size 3 (== dlen)", d3, "ABCDE", 3);
	fail += test_case("dst 3: size 4 (> dlen)", d3, "ABCDE", 4);
	fail += test_case("dst 3: size 6 (truncated)", d3, "ABCDE", 6);
	fail += test_case("dst 3: size 9 (exact fit)", d3, "ABCDE", 9);
	fail += test_case("dst 3: size 10", d3, "ABCDE", 10);
	fail += test_case("dst 3: long src, size 10", d3, "ABCDE12345", 10);
	fail += test_case("dst 3: empty src, size 10", d3, "", 10);
	fail += test_case("dst 3: empty src, size 0", d3, "", 0);
	fail += test_case("dst empty: size 10", d0, "ABCDE", 10);
	fail += test_case("dst empty: size 1", d0, "ABCDE", 1);
	fail += test_case("dst no NUL: size 10", dn, "ABCDE", 10);
	fail += test_case("dst no NUL: size 6", dn, "ABCDE", 6);
	fail += test_case("dst no NUL: size 3", dn, "ABCDE", 3);
	fail += test_case("dst no NUL: size 0", dn, "ABCDE", 0);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strlcat());
}
