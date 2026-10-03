#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, !!isalpha(c) == !!ft_isalpha(c)));
}

int	test_ft_isalpha(void)
{
	int fail = 0;

	printf("===== test_ft_isalpha =====\n");
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
	return (test_ft_isalpha());
}
