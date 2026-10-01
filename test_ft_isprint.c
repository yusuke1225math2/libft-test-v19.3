#include "test_libft.h"

static void	test_case(int c)
{
	printf("case: c == %d ('%c' in char)\n", c, c);
	printf("isprint:	%d\n", isprint(c));
	printf("ft_isprint:	%d\n", ft_isprint(c));
	printf("\n");
}

void	test_ft_isprint(void)
{
	test_case(31);
	test_case(' ');
	test_case('&');
	test_case('~');
	test_case(127);
}

int	main(void)
{
	test_ft_isprint();
}
