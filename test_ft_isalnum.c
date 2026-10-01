#include "test_libft.h"

static void	test_case(int c)
{
	printf("case: c == %d ('%c' in char)\n", c, c);
	printf("isalnum:	%d\n", isalnum(c));
	printf("ft_isalnum:	%d\n", ft_isalnum(c));
	printf("\n");
}

void	test_ft_isalnum(void)
{
	test_case(' ');
	test_case(-1);
	test_case('0');
	test_case('9');
	test_case('a');
	test_case('z');
}

int	main(void)
{
	test_ft_isalnum();
}
