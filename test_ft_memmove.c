/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:57:56 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 00:39:41 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

#define BUF_SIZE 16

static int	test_case(const char *name, const void *src, size_t n)
{
	unsigned char	a[BUF_SIZE];
	unsigned char	b[BUF_SIZE];
	void			*ra;
	void			*rb;

	memset(a, '.', BUF_SIZE);
	memset(b, '.', BUF_SIZE);
	ra = memmove(a, src, n);
	rb = ft_memmove(b, src, n);
	return (result(name, memcmp(a, b, BUF_SIZE) == 0 && ra == a && rb == b));
}

static int	test_null(void)
{
	return (result("NULL NULL", ft_memmove(NULL, NULL, 3) == NULL));
}

static int	test_int_array(void)
{
	int	src[4] = {1, 2, 3, 4};
	int	a[4] = {0};
	int	b[4] = {0};

	memmove(a, src, sizeof(src));
	ft_memmove(b, src, sizeof(src));
	return (result("int array", memcmp(a, b, sizeof(a)) == 0));
}

static int	test_overlap(const char *name, size_t dst_off,
							size_t src_off, size_t n)
{
	char	a[BUF_SIZE] = "0123456789";
	char	b[BUF_SIZE] = "0123456789";
	void	*ra;
	void	*rb;
	int		ok;

	ra = memmove(a + dst_off, a + src_off, n);
	rb = ft_memmove(b + dst_off, b + src_off, n);
	ok = (memcmp(a, b, BUF_SIZE) == 0)
		&& ra == a + dst_off && rb == b + dst_off;
	return (result(name, ok));
}

int	test_ft_memmove(void)
{
	int	fail;

	printf("===== test_ft_memmove =====\n");
	fail = 0;
	fail += test_case("normal", "ABCDE", 3);
	fail += test_case("n=0", "ABCDE", 0);
	fail += test_case("full", "0123456789abcdef", BUF_SIZE);
	fail += test_case("nul-byte", "A\0B", 3);
	fail += test_case("high bytes", "\xff\x80\x7f", 3);
	fail += test_int_array();
	fail += test_null();
	fail += test_overlap("overlap dst>src", 2, 0, 5);
	fail += test_overlap("overlap dst<src", 0, 2, 5);
	fail += test_overlap("overlap dst>src by 1", 1, 0, 9);
	fail += test_overlap("overlap dst<src by 1", 0, 1, 9);
	fail += test_overlap("overlap dst==src", 0, 0, 5);
	fail += test_overlap("adjacent", 5, 0, 5);
	fail += test_overlap("overlap n=0", 2, 0, 0);
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_memmove());
}
