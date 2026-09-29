#include "test_libft.h"

static int	test_case(const char *name, size_t nmemb, size_t size)
{
	unsigned char	*a;
	unsigned char	*b;
	int				ok;

	a = calloc(nmemb, size);
	b = ft_calloc(nmemb, size);
	ok = (a == NULL) == (b == NULL);
	if (ok && a && b && nmemb * size > 0)
		ok = memcmp(a, b, nmemb * size) == 0;
	if (ok && b && nmemb * size > 0)
		b[nmemb * size - 1] = 1;
	free(a);
	free(b);
	return (result(name, ok));
}

static int	test_dirty_reuse(void)
{
	unsigned char	*p;
	size_t			i;
	int				ok;

	p = malloc(16);
	memset(p, 0xAA, 16);
	free(p);
	p = ft_calloc(8, 2);
	ok = p != NULL;
	i = 0;
	while (ok && i < 16)
		ok = p[i++] == 0;
	free(p);
	return (result("dirty reuse", ok));
}

int	test_ft_calloc(void)
{
	int	fail;

	fail = 0;
	fail += test_case("normal bytes", 5, 1);
	fail += test_case("normal ints", 10, sizeof(int));
	fail += test_case("odd sizes", 3, 7);
	fail += test_case("nmemb 0", 0, 5);
	fail += test_case("size 0", 5, 0);
	fail += test_case("both 0", 0, 0);
	fail += test_case("overflow a", (size_t)-1, 2);
	fail += test_case("overflow b", 2, (size_t)-1);
	fail += test_case("overflow edge", (size_t)-1 / 2 + 1, 2);
	fail += test_case("huge no overflow", (size_t)-1, 1);
	fail += test_dirty_reuse();
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_calloc());
}
