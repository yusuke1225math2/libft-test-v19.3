/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 00:20:05 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, char const *s1, char const *s2,
					const char *exp)
{
	char	*r;
	int		ok;

	r = ft_strjoin(s1, s2);
	if (!r)
		ok = r == exp;
	else
		ok = exp && strcmp(r, exp) == 0;
	free(r);
	return (result(name, ok));
}

int	test_ft_strjoin(void)
{
	int	fail;

	printf("===== test_ft_strjoin =====\n");
	fail = 0;
	fail += test_case("s2 is NULL", "123", NULL, NULL);
	fail += test_case("s1 is NULL", NULL, "4567", NULL);
	fail += test_case("both are NULL", NULL, NULL, NULL);
	fail += test_case("both are empty", "", "", "");
	fail += test_case("s2 is empty", "123", "", "123");
	fail += test_case("s1 is empty", "", "4567", "4567");
	fail += test_case("normal", "123", "4567", "1234567");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strjoin());
}
