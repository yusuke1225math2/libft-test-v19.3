#include "test_libft.h"

static void	test_case(int c)
{
	printf("case: c == %d ('%c' in char)\n", c, c);
	printf("isdigit:	%d\n", isdigit(c));
	printf("ft_isdigit:	%d\n", ft_isdigit(c));
	printf("\n");
}

void	test_ft_isdigit(void)
{
	test_case('a');
	test_case('0');
	test_case('5');
	test_case('9');
	test_case('A');
}

int	main(void)
{
	test_ft_isdigit();
}
