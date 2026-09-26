#include "test_libft.h"

void	test_case(char const *s, unsigned int start, size_t len)
{
	char	*r;

	r = ft_substr(s, start, len);
	printf("s: \"%s\", start: %u, len: %zu, return: \"%s\"\n", s, start, len, r);
	free(r);
}

int	main(void)
{
	char	*sn;
	char	*se;
	char	*s;

	printf("===== Case: s is NULL =====\n");
	sn = NULL;
	test_case(sn, 0, 0);
	printf("===== Case: s is an empty string =====\n");
	se = "";
	printf("---- When start is in s -----\n");
	test_case(se, 0, 0);
	test_case(se, 0, 2);
	printf("---- When start is out of s -----\n");
	test_case(se, 1, 0);
	test_case(se, 1, 2);
	printf("===== Case: s is a normal string =====\n");
	s = "12345";
	printf("---- When start is in s -----\n");
	test_case(s, 0, 0);
	test_case(s, 0, 2);
	test_case(s, 1, 0);
	test_case(s, 1, 3);
	test_case(s, 1, 6);
	printf("---- When start is out of s -----\n");
	test_case(s, 6, 0);
	test_case(s, 6, 3);
}
