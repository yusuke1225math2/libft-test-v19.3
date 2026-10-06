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

ssize_t	read_all(int fd, char *buf, size_t size)
{
	ssize_t	total;
	ssize_t	n;

	total = 0;
	while ((size_t) total < size)
	{
		n = read(fd, buf + total, size - total);
		if (n < 0)
			return (-1);
		if (n == 0)
			break ;
		total += n;
	}
	return (total);
}

int	check_output(const char *name, int fds[2], const char *exp,
			size_t exp_len)
{
	char	buf[64];
	ssize_t	n;

	close(fds[1]);
	n = read_all(fds[0], buf, sizeof(buf));
	close(fds[0]);
	if (n != (ssize_t)exp_len || memcmp(buf, exp, exp_len) != 0)
		printf("  got %zd bytes: [%.*s]\n", n, (int)(n > 0 ? n : 0), buf);
	return (result(name, n == (ssize_t)exp_len
				&& memcmp(buf, exp, exp_len) == 0));
}
