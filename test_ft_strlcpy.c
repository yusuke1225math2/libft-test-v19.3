/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:25:59 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 01:05:04 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

#define BUF_SIZE 4

static int	test_case(const char *name, size_t size)
{
	char	da[BUF_SIZE] = "123";
	char	db[BUF_SIZE] = "123";
	size_t	ra;
	size_t	rb;
	int		ok;

	ra = strlcpy(da, "ABCDE", size);
	rb = ft_strlcpy(db, "ABCDE", size);
	ok = (ra == rb) && (memcmp(da, db, BUF_SIZE) == 0);
	return (result(name, ok));
}

int	test_ft_strlcpy(void)
{
	int	fail;

	printf("===== test_ft_strlcpy =====\n");
	fail = 0;
	fail += test_case("size: 0", 0);
	fail += test_case("size: 2", 2);
	fail += test_case("size: 4", 4);
	fail += test_case("size: 5", 5);
	fail += test_case("size: 8", 8);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strlcpy());
}
