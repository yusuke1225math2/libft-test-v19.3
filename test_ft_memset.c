#include "test_libft.h"

void	test_case(char *s1, char *s2, int c, size_t n)
{
	printf("s1:		\"%s\"\n", s1);
	memset(s1, c, n);
	printf("memset:		\"%s\"\n", s1);
	printf("s2:		\"%s\"\n", s2);
	ft_memset(s2, c, n);
	printf("ft_memset:	\"%s\"\n", s2);
}

int	main(void)
{
	char	s1[6] = "12345";
	char	s2[6] = "12345";
	test_case(s1, s2, 'A', 3);

}
