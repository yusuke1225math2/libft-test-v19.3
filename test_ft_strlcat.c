#include "test_libft.h"

#define BUF_SIZE 10

void	print_with_write(char *buff)
{
	int	i;

	i = 0;
	while (i < BUF_SIZE)
	{
		write(1, &buff[i], 1);
		if (buff[i] == 0)
			ft_putchar_fd('N', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	test_case(char *dst, const char *src, size_t dsize)
{
	printf("strlcat:	%lu, dst: \"%s\"\n", strlcat(dst, src, dsize), dst);
	print_with_write(dst);
}

void	ft_test_case(char *dst, const char *src, size_t dsize)
{
	printf("ft_strlcat:	%lu, dst: \"%s\"\n", ft_strlcat(dst, src, dsize), dst);
	print_with_write(dst);
}

void	print_test_case(char *dst, const char *src, size_t dsize)
{
	printf("dst[%d]: \"%s\", src: \"%s\", dsize: %lu\n", BUF_SIZE, dst, src, dsize);
}

void	test_compare(char *dst, char *dst_ft, const char *src, size_t dsize)
{
	print_test_case(dst, src, dsize);
	test_case(dst, src, dsize);
	ft_test_case(dst_ft, src, dsize);
	printf("\n");
}

int	main(void)
{
	// normal
	char	dst1[BUF_SIZE] = "123";
	char	dft1[BUF_SIZE] = "123";
	test_compare(dst1, dft1, "ABCDE", BUF_SIZE);

	// normal src is truncated 
	char	dst2[BUF_SIZE] = "123";
	char	dft2[BUF_SIZE] = "123";
	test_compare(dst2, dft2, "ABCDE12345", BUF_SIZE);

	// normal: dsize < BUF_SIZE && dsize > strlen(dst)
	char	dst3[BUF_SIZE] = "123";
	char	dft3[BUF_SIZE] = "123";
	test_compare(dst3, dft3, "ABCDEF", 6);

	// normal: dsize < strlen(dst)
	char	dst4[BUF_SIZE] = "123";
	char	dft4[BUF_SIZE] = "123";
	test_compare(dst4, dft4, "ABCDE", 2);

	// normal: dsize == 0
	char	dst5[BUF_SIZE] = "123";
	char	dft5[BUF_SIZE] = "123";
	test_compare(dst5, dft5, "ABCDE", 0);

	// error: dst is not null-terminated
	char	dst6[BUF_SIZE];
	char	dft6[BUF_SIZE];
	int		i;
	i = 0;
	while (i < BUF_SIZE)
	{
		dst6[i] = '0' + i;
		dft6[i] = dst6[i];
		i++;
	}
	test_compare(dst6, dft6, "ABCDE", 10);
	test_compare(dst6, dft6, "ABCDE", 6);
	test_compare(dst6, dft6, "ABCDE", 3);
	test_compare(dst6, dft6, "ABCDE", 0);

	// error: src is null string
	char	dst7[BUF_SIZE] = "123";
	char	dft7[BUF_SIZE] = "123";
	test_compare(dst7, dft7, "", BUF_SIZE);

	// error: src is null string (with memory dusts)
	char	dst8[BUF_SIZE] = "123";
	char	dft8[BUF_SIZE] = "123";
	char	src[BUF_SIZE];
	src[0] = '\0';
	i = 1;
	while (i < BUF_SIZE)
		src[i++] = 'E';
	print_test_case(dst8, src, BUF_SIZE);
	strlcat(dst8, src, BUF_SIZE);
	print_with_write(dst8);
	ft_strlcat(dft8, src, BUF_SIZE);
	print_with_write(dft8);
}
