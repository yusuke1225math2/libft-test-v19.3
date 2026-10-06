#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, toupper(c) == ft_toupper(c)));
}

int	test_ft_toupper(void)
{
	int	fail = 0;

	printf("===== test_ft_toupper =====\n");
	fail += test_case("\' \'", ' ');
	fail += test_case("\'0\'", '0');
	fail += test_case("\'A\'", 'A');
	fail += test_case("\'a\'", 'a');
	fail += test_case("\'z\'", 'z');
	fail += test_case("before 'A'", '@');
	fail += test_case("after 'Z'", '[');
	fail += test_case("before 'a'", '`');
	fail += test_case("after 'z'", '{');
	fail += test_case("EOF", EOF);
	fail += test_case("128", 128);
	fail += test_case("255", 255);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_toupper());
}
