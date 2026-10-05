/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:19:37 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 01:25:23 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

#define BUF_SIZE 10

static int	test_case(const char *name, const char *src, size_t size)
{
	char	da[BUF_SIZE] = "123";
	char	db[BUF_SIZE] = "123";
	size_t	ra;
	size_t	rb;
	int		ok;

	ra = strlcat(da, src, size);
	rb = ft_strlcat(db, src, size);
	ok = (ra == rb) && (memcmp(da, db, BUF_SIZE) == 0);
	return (result(name, ok));
}

//void	print_with_write(char *buff)
//{
//	int	i;
//
//	i = 0;
//	while (i < BUF_SIZE)
//	{
//		write(1, &buff[i], 1);
//		if (buff[i] == 0)
//			ft_putchar_fd('N', 1);
//		i++;
//	}
//	ft_putchar_fd('\n', 1);
//}
//
//void	print_test_case(char *dst, const char *src, size_t dsize)
//{
//	printf("dst[%d]: \"%s\", src: \"%s\", dsize: %lu\n", BUF_SIZE, dst, src, dsize);
//}
//
//void	test_compare(char *dst, char *dst_ft, const char *src, size_t dsize)
//{
//	print_test_case(dst, src, dsize);
//	test_case(dst, src, dsize);
//	ft_test_case(dst_ft, src, dsize);
//	printf("\n");
//}

int	test_ft_strlcat(void)
{
	int	fail;

	printf("===== test_ft_strlcat =====\n");
	fail = 0;
	fail += test_case("normal", "ABCDE", BUF_SIZE);
	fail += test_case("dsize < strlen(dst)", "ABCDE", 2);
	fail += test_case("src is truncated", "ABCDE12345", 2);
	fail += test_case("dsize < BUF_SIZE && dsize > strlen(dst)", "ABCDE", 6);
	fail += test_case("dsize == 0", "ABCDE", 0);
	fail += test_case("src is null string", "", BUF_SIZE);
	// error: dst is not null-terminated
	//char	dst6[BUF_SIZE];
	//char	dft6[BUF_SIZE];
	//int		i;
	//i = 0;
	//while (i < BUF_SIZE)
	//{
	//	dst6[i] = '0' + i;
	//	dft6[i] = dst6[i];
	//	i++;
	//}
	//test_compare(dst6, dft6, "ABCDE", 10);
	//test_compare(dst6, dft6, "ABCDE", 6);
	//test_compare(dst6, dft6, "ABCDE", 3);
	//test_compare(dst6, dft6, "ABCDE", 0);

	//// error: src is null string (with memory dusts)
	//char	dst8[BUF_SIZE] = "123";
	//char	dft8[BUF_SIZE] = "123";
	//char	src[BUF_SIZE];
	//src[0] = '\0';
	//i = 1;
	//while (i < BUF_SIZE)
	//	src[i++] = 'E';
	//print_test_case(dst8, src, BUF_SIZE);
	//strlcat(dst8, src, BUF_SIZE);
	//print_with_write(dst8);
	//ft_strlcat(dft8, src, BUF_SIZE);
	//print_with_write(dft8);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strlcat());
}
