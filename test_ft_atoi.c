#include "test_libft.h"

static int	test_case(const char *name, const char *s)
{
	return (result(name, atoi(s) == ft_atoi(s)));
}

int	test_ft_atoi(void)
{
	int	fail;

	printf("===== test: ft_atoi =====\n");
	fail = 0;
	fail += test_case("\"\"", "");
	fail += test_case("\" 	01234\"", " 	01234");
	fail += test_case("\"	 +12345\"", "	 +12345");
	fail += test_case("\"	 -12345\"", "	 -12345");
	fail += test_case("\"	 +-12345\"", "	 +-12345");
	fail += test_case("\"	 --12345\"", "	 --12345");
	fail += test_case("\"123AB\"", "123AB");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_atoi());
}
