#include "../libft.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <unistd.h>

int		result(const char *name, int ok);
void	result_all(int fail);
ssize_t	read_all(int fd, char *buf, size_t size);
int		check_output(const char *name, int fds[2], const char *exp,
			size_t exp_len);
