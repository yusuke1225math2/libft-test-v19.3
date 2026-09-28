#include "test_libft.h"

static int	test_case(const char *name, const char *big,
						const char *little, size_t len)
{
	char	*a;
	char	*b;
	int		ok;

	a = strnstr(big, little, len);
	b = ft_strnstr(big, little, len);
	ok = a == b;
	return (result(name, ok));
}

int	test_ft_calloc(void)
{
	int	fail;

	fail = 0;
	fail += test_case("match", "0123456789", "3456", 10);
	fail += test_case("matches the first", "01010101", "01", 8);
	fail += test_case("match at 0", "0123456789", "012", 10);
	fail += test_case("match at end", "0123456789", "89", 10);
	fail += test_case("no match", "0123456789", "a", 10);
	fail += test_case("short len no match ", "0123456789", "3456", 5);
	fail += test_case("empty little", "0123456789", "", 10);
	fail += test_case("empty big", "", "a", 10);
	fail += test_case("zero len", "0123456789", "3456", 0);
	fail += test_case("fits exactly in len", "0123456789", "3456", 7);
	fail += test_case("one short of len", "0123456789", "3456", 6);
	fail += test_case("len > strlen(big)", "0123456789", "89", 100);
	fail += test_case("len max", "0123456789", "789", (size_t)-1);
	fail += test_case("partial then match", "aaab", "aab", 4);
	fail += test_case("match cut by len", "aaab", "aab", 3);
	fail += test_case("partial at end", "0123456789", "89a", 10);
	fail += test_case("little longer than big", "abc", "abcd", 10);
	fail += test_case("little == big", "abc", "abc", 3);
	fail += test_case("empty little, len 0", "abc", "", 0);
	fail += test_case("both empty", "", "", 0);
	fail += test_case("NUL before len", "abc\0def", "def", 7);
	fail += test_case("case sensitive", "Hello", "hello", 5);
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_calloc());
}
