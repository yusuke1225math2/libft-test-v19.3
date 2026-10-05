/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:58:48 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:14:22 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_ft_putstr_fd(void)
{
	int	fail;

	printf("===== test_ft_putstr_fd =====\n");
	fail = 0;
	ft_putstr_fd("ABCDEF", 1);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_putstr_fd());
}
