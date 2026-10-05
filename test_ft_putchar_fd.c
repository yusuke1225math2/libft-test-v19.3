/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:58:23 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:35:45 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_ft_putchar_fd(void)
{
	int	fail;

	printf("===== test_ft_putchar_fd =====\n");
	fail = 0;
	ft_putchar_fd('a', 1);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_putchar_fd());
}
