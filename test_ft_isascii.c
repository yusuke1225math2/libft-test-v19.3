#include "test_libft.h"

void	test_case(int c)
{
	printf("case: c == %d\n", c);
	printf("isascii:	%d\n", isascii(c));
	printf("ft_isascii:	%d\n", ft_isascii(c));
	printf("\n");
}

void	test_ft_isascii(void)
{
	test_case(-1);
	test_case(0);
	test_case(50);
	test_case(127);
	test_case(200);
}

int	main(void)
{
	test_ft_isascii();
}
