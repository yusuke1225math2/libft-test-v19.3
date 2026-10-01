#include "test_libft.h"

static void	test_case(int c)
{
	printf("case: c == %d ('%c' in char)\n", c, c);
	printf("toupper:	'%c'\n", toupper(c));
	printf("ft_toupper:	'%c'\n", ft_toupper(c));
	printf("\n");
}

void	test_ft_toupper(void)
{
	test_case(' ');
	test_case('0');
	test_case('A');
	test_case('a');
	test_case('z');
}

int	main(void)
{
	test_ft_toupper();
}
