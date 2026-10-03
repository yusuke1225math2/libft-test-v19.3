#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, !!isascii(c) == !!ft_isascii(c)));
}

int	test_ft_isascii(void)
{
	int	fail = 0;

	printf("===== test_ft_isascii =====\n");
	fail += test_case("INT_MIN", INT_MIN);
	fail += test_case("-1000", -1000);
	fail += test_case("EOF", EOF);
	fail += test_case("0", 0);
	fail += test_case("127 last ascii", 127);
	fail += test_case("128 after ascii", 128);
	fail += test_case("200", 200);
	fail += test_case("255", 255);
	fail += test_case("256", 256);
	fail += test_case("INT_MAX", INT_MAX);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_isascii());
}
