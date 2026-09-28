#include "test_libft.h"

int	result(const char *name, int ok)
{
	printf("%-30s %s\n", name, ok ? "OK" : "KO");
	return (!ok);
}

void	result_all(int fail)
{
	if (fail)
		printf("\n%d test(s) failed\n", fail);
	else
		printf("\nall tests passed\n");
}	
