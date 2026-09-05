#include "test_libft.h"

void	test_case(int c)
{
	printf("case: c == %d ('%c' in char)\n", c, c);
	printf("tolower:	'%c'\n", tolower(c));
	printf("ft_tolower:	'%c'\n", ft_tolower(c));
	printf("\n");
}

int	main(void)
{
	test_case(' ');
	test_case('0');
	test_case('a');
	test_case('A');
	test_case('Z');
}
