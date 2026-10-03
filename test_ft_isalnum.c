#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, !!isalnum(c) == !!ft_isalnum(c)));
}

int	test_ft_isalnum(void)
{
	int	fail = 0;

	printf("===== test_ft_isalnum =====\n");
	fail += test_case("'/' before '0'", '/');
	fail += test_case("'0'", '0');
	fail += test_case("'9'", '9');
	fail += test_case("':' after '9'", ':');
	fail += test_case("'@' before 'A'", '@');
	fail += test_case("'A'", 'A');
	fail += test_case("'Z'", 'Z');
	fail += test_case("'[' after 'Z'", '[');
	fail += test_case("'`' before 'a'", '`');
	fail += test_case("'a'", 'a');
	fail += test_case("'z'", 'z');
	fail += test_case("'{' after 'z'", '{');
	fail += test_case("EOF", EOF);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_isalnum());
}
