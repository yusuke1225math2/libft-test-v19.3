#include "test_libft.h"

int	result(const char *name, int ok)
{
	printf("%s: %s\n", ok ? "OK" : "KO", name);
	return (!ok);
}

void	result_all(int fail)
{
	if (fail)
		printf("\n%d test(s) failed\n", fail);
	else
		printf("\nall tests passed\n");
}	
