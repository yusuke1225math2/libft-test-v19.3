/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/26 15:39:32 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void	test_case(int n)
{
	char	*r;

	r = ft_itoa(n);
	printf("n: %d, return: \"%s\"", n, r);
	printf("\n");
	free(r);
}

int	main(void)
{
	test_case(2147483647);
	test_case(12045);
	test_case(0);
	test_case(-0);
	test_case(-12045);
	test_case(-2147483647 - 1);
}
