#include "test_libft.h"

int	main(void)
{
	int	fd;

	fd = 1;
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(123456, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-123456, fd);
}
