/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:12:14 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_ft_putendl_fd(void)
{
	int	fail;

	printf("===== test_ft_putendl_fd =====\n");
	fail = 0;
	ft_putendl_fd("123456", 1);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_putendl_fd());
}
