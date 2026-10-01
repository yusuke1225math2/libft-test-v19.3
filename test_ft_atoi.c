#include "test_libft.h"

static void	test_case(char *s)
{
	printf("case: \"%s\"\n", s);
	printf("atoi:		%d\n", atoi(s));
	printf("ft_atoi:	%d\n", ft_atoi(s));
	printf("\n");
}

void	test_ft_atoi(void)
{
	test_case("");
	test_case(" 	01234");
	test_case("	 +12345");
	test_case("	 -12345");
	test_case("	 +-12345");
	test_case("	 --12345");
	test_case("123AB");
}

int	main(void)
{
	test_ft_atoi();
}
