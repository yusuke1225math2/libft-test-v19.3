/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:58:42 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:13:29 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_ft_putnbr_fd(void)
{
	int	fail;
	int	fd;

	printf("===== test_ft_putnbr_fd =====\n");
	fail = 0;
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
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_putnbr_fd());
}
