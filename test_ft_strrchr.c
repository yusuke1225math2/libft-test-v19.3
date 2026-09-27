#include "test_libft.h"

static int	result(const char *name, int ok)
{
	printf("%-12s %s\n", name, ok ? "OK" : "KO");
	return (!ok);
}

static int	test_case(const char *name, const char *s, int c)
{
	char	*ra;
	char	*rb;

	ra = strrchr(s, c);
	rb = ft_strrchr(s, c);
	printf("ra: [%s]\nrb: [%s]\n", ra, rb);
	return (result(name, ra == rb));
}

int	test_ft_strrchr(void)
{
	int	fail;

	fail = 0;
	fail += test_case("repeated", "ABCABC", 'A');
	fail += test_case("repeated end", "ABCABC", 'C');
	fail += test_case("once", "ABC", 'B');
	fail += test_case("single", "a", 'a');
	fail += test_case("not found", "ABCABC", 'z');
	fail += test_case("nul", "ABCABC", '\0');
	fail += test_case("empty nul", "", '\0');
	fail += test_case("empty a", "", 'a');
	fail += test_case("c+256", "ABCABC", 'B' + 256);
	fail += test_case("256 -> nul", "ABCABC", 256);
	fail += test_case("high byte", "A\xe9" "B\xe9", 0xe9);
	fail += test_case("negative byte", "A\xe9" "B\xe9", -23);
	if (fail)
		printf("\n%d test(s) failed\n", fail);
	else
		printf("\nall tests passed\n");
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_strrchr());
}
