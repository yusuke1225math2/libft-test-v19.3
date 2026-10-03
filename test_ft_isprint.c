#include "test_libft.h"

static int	test_case(const char *name, int c)
{
	return (result(name, !!isprint(c) == !!ft_isprint(c)));
}

int	test_ft_isprint(void)
{
	int	fail = 0;

	printf("===== test_ft_isprint =====\n");
	fail += test_case("'31'", 31);
	fail += test_case("' '", ' ');
	fail += test_case("'&'", '&');
	fail += test_case("'~'", '~');
	fail += test_case("'127'", 127);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	test_ft_isprint();
}
