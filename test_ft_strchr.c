#include "test_libft.h"

static int	test_case(const char *name, const char *s, int c)
{
	char	*ra;
	char	*rb;

	ra = strchr(s, c);
	rb = ft_strchr(s, c);
	printf("ra: [%s]\nrb: [%s]\n", ra, rb);
	return (result(name, ra == rb));
}

int	test_ft_strchr(void)
{
	int	fail;

	printf("===== test_ft_strchr =====\n");
	fail = 0;
	fail += test_case("middle", "ABC", 'B');
	fail += test_case("last", "ABC", 'C');
	fail += test_case("not found", "ABC", 'z');
	fail += test_case("c+256", "ABC", 'B' + 256);
	fail += test_case("256(NULL)", "ABC", 256);
	fail += test_case("high byte", "AB\xe9", 0xe9);
	fail += test_case("negative byte", "AB\xe9", -23);
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_strchr());
}
