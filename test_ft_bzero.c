#include "test_libft.h"

void	test_case(char *s1, char *s2, size_t n)
{
	printf("s1:		\"%s\"\n", s1);
	bzero(s1, n);
	printf("bzero:		\"%s\"\n", s1);
	printf("s2:		\"%s\"\n", s2);
	ft_bzero(s2, n);
	printf("ft_bzero:	\"%s\"\n\n", s2);
}

void	test_ft_bzero(void)
{
	char	s1[6] = "12345";
	char	s2[6] = "12345";
	test_case(s1, s2, 6);
}

int	main(void)
{
	test_ft_bzero();
}
