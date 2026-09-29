#include "test_libft.h"

static int	test_case(const char *name, const void *s, int c, size_t n)
{
	void	*ra;
	void	*rb;

	ra = memchr(s, c, n);
	rb = ft_memchr(s, c, n);
	return (result(name, ra == rb));
}

static int	test_buffers(void)
{
	int	arr[3];
	int	fail;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	fail = 0;
	fail += test_case("int arr 2", arr, 2, sizeof(arr));
	fail += test_case("int arr 0", arr, 0, sizeof(arr));
	fail += test_case("int arr 9", arr, 9, sizeof(arr));
	return (fail);
}

int	test_ft_memchr(void)
{
	int	fail;

	fail = 0;
	fail += test_case("middle", "ABC", 'B', 3);
	fail += test_case("last", "ABC", 'C', 3);
	fail += test_case("n==0", "ABC", 'C', 0);
	fail += test_case("not found", "ABC", 'z', 3);
	fail += test_case("c+256", "ABC", 'B' + 256, 3);
	fail += test_case("256->0 miss", "ABC", 256, 3);
	fail += test_case("high byte", "AB\xe9", 0xe9, 3);
	fail += test_case("neg byte", "AB\xe9", -23, 3);
	fail += test_case("past NUL", "AB\0CD", 'C', 5);
	fail += test_case("find NUL", "ABC", '\0', 4);
	fail += test_case("beyond n", "ABC", 'C', 2);
	fail += test_case("first", "ABC", 'A', 3);
	fail += test_case("dup", "ABAB", 'B', 4);
	fail += test_buffers();
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_memchr());
}
