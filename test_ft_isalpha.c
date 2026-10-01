#include "test_libft.h"

static void	test_case(int c)
{
	printf("case: c == %d ('%c' in char)\n", c, c);
	printf("isalpha:	%d\n", isalpha(c));
	printf("ft_isalpha:	%d\n", ft_isalpha(c));
	printf("\n");
}

void test_ft_isalpha(void)
{
	test_case('1');
	test_case('a');
	test_case('Z');
	test_case(-1);
	test_case(1000);
	test_case(-1000);
}

int	main(void)
{
	test_ft_isalpha();
}
