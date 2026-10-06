/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:32:04 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 00:29:02 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, char const *s, unsigned int start,
					size_t len, char *exp)
{
	char	*r;
	int		ok;

	r = ft_substr(s, start, len);
	if (!r)
		ok = r == exp;
	else
		ok = exp && strcmp(r, exp) == 0;
	free(r);
	return (result(name, ok));
}

int	test_ft_substr(void)
{
	int		fail;

	printf("===== test_ft_substr =====\n");
	fail = 0;
	fail += test_case("s is NULL", NULL, 0, 0, NULL);
	fail += test_case("empty s, start 0, len 0", "", 0, 0, "");
	fail += test_case("empty s, start 0, len 2", "", 0, 2, "");
	fail += test_case("empty s, start 1, len 0", "", 1, 0, "");
	fail += test_case("empty s, start 1, len 2", "", 1, 2, "");
	fail += test_case("normal s, start 0, len 0", "12345", 0, 0, "");
	fail += test_case("normal s, start 0, len 2", "12345", 0, 2, "12");
	fail += test_case("normal s, start 1, len 0", "12345", 1, 0, "");
	fail += test_case("normal s, start 1, len 3", "12345", 1, 3, "234");
	fail += test_case("normal s, start 1, len 6", "12345", 1, 6, "2345");
	fail += test_case("normal s, start 6, len 0", "12345", 6, 0, "");
	fail += test_case("normal s, start 6, len 3", "12345", 6, 3, "");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_substr());
}
