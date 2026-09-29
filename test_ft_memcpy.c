#include "test_libft.h"

#define BUF_SIZE 16

static int	test_case(const char *name, const void *src, size_t n)
{
	unsigned char	a[BUF_SIZE];
	unsigned char	b[BUF_SIZE];
	void	*ra;
	void	*rb;

	memset(a, '.', BUF_SIZE);
	memset(b, '.', BUF_SIZE);
	ra = memcpy(a, src, n);
	rb = ft_memcpy(b, src, n);
	return (result(name, memcmp(a, b, BUF_SIZE) == 0 && ra == a && rb == b));
}

static int	test_null(void)
{
	return (result("NULL NULL", ft_memcpy(NULL, NULL, 3) == NULL));
}

static int	test_int_array(void)
{
	int	src[4] = {1, 2, 3, 4};
	int	a[4] = {0};
	int	b[4] = {0};

	memcpy(a, src, sizeof(src));
	ft_memcpy(b, src, sizeof(src));
	return (result("int array", memcmp(a, b, sizeof(a)) == 0));
}

int	test_ft_memcpy(void)
{
	int	fail;

	fail = 0;
	fail += test_case("normal", "ABCDE", 3);
	fail += test_case("n=0", "ABCDE", 0);
	fail += test_case("full", "0123456789abcdef", BUF_SIZE);
	fail += test_case("nul-byte", "A\0B", 3);
	fail += test_case("high bytes", "\xff\x80\x7f", 3);
	fail += test_int_array();
	fail += test_null();
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_memcpy());
}
