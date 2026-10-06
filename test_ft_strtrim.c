/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 00:15:09 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, char const *s1, char const *set,
						const char *exp)
{
	char	*r;
	int		ok;

	r = ft_strtrim(s1, set);
	if (!r)
		ok = r == exp;
	else
		ok = exp && strcmp(r, exp) == 0;
	free(r);
	return (result(name, ok));
}

int	test_ft_strtrim(void)
{
	int		fail;

	printf("===== test_ft_strtrim =====\n");
	fail = 0;
	fail += test_case("s1 is NULL", NULL, " ", NULL);
	fail += test_case("set is NULL", "abc", NULL, NULL);
	fail += test_case("s1 is empty", "", "xyz", "");
	fail += test_case("s1 is of set", "xxyzyzxx", "xyz", "");
	fail += test_case("trimmed", "yyxxzzABCDEFxyzxyz", "xyz", "ABCDEF");
	fail += test_case("not trimmed", "AxByCzD", "xyz", "AxByCzD");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strtrim());
}
