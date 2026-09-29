/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_template.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/26 12:43:01 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name)
{
	int	ok;

	ok = 1;
	return (result(name, ok));
}

int	test_ft_template(void)
{
	int	fail;

	fail = 0;
	fail += test_case("first case");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_template());
}
