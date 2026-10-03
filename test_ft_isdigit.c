#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, !!isdigit(c) == !!ft_isdigit(c)));
}

int	test_ft_isdigit(void)
{
	int	fail = 0;

	printf("===== test_ft_isdigit =====\n");
	fail += test_case("'/' before '0'", '/');
	fail += test_case("'0'", '0');
	fail += test_case("'9'", '9');
	fail += test_case("':' after '0'", ':');
	fail += test_case("EOF", EOF);
}

int	main(void)
{
	return (test_ft_isdigit());
}
