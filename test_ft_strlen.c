#include "test_libft.h"

static int	test_case(const char *name, const char *s)
{
	return (result(name, strlen(s) == ft_strlen(s)));
}

int	test_ft_strlen(void)
{
	int		fail;
	char	s[] = "ab\0cd";

	printf("===== test_ft_strlen =====\n");
	fail = 0;
	fail += test_case("\"\"", "");
	fail += test_case("\"12345\"", "12345");
	fail += test_case("embedded NUL", s);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strlen());
}
