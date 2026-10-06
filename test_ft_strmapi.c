/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 00:19:42 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static char	idx_more_than_second(unsigned int i, char c)
{
	if (i > 2)
		return ('T');
	return (c);
}

static char	to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static int	test_case(const char *name, char const *s,
						char (*f)(unsigned int, char), const char *exp)
{
	char	*r;
	int		ok;

	r = ft_strmapi(s, f);
	if (!r)
		ok = r == exp;
	else
		ok = exp && strcmp(r, exp) == 0;
	free(r);
	return (result(name, ok));
}

int	test_ft_strmapi(void)
{
	int	fail;

	printf("===== test_ft_strmapi =====\n");
	fail = 0;
	fail += test_case("s is NULL", NULL, idx_more_than_second, NULL);
	fail += test_case("f is NULL", "hello", NULL, NULL);
	fail += test_case("idx_more_than_second", "012345", idx_more_than_second, "012TTT");
	fail += test_case("to_upper_even", "abcdef", to_upper_even, "AbCdEf");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strmapi());
}
