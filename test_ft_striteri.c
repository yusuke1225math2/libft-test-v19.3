/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 00:26:25 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static void	idx_more_than_second(unsigned int i, char *c)
{
	if (i > 2)
		*c = 'T';
}

static void	to_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

static int	test_case(const char *name, char *s, void (*f)(unsigned int, char*),
						const char *exp)
{
	int	ok;

	ft_striteri(s, f);
	if (!s)
		ok = s == exp;
	else
		ok = strcmp(s, exp) == 0;
	return (result(name, ok));
}

int	test_ft_striteri(void)
{
	int		fail;
	char	s1[] = "hello";
	char	s2[] = "01234567889";
	char	s3[] = "abcdefghijk";

	printf("===== test_ft_striteri =====\n");
	fail = 0;
	fail += test_case("s is NULL", NULL, idx_more_than_second, NULL);
	fail += test_case("f is NULL", s1, NULL, "hello");
	fail += test_case("idx_more_than_second", s2, idx_more_than_second, "012TTTTTTTT");
	fail += test_case("to_upper_even", s3, to_upper_even, "AbCdEfGhIjK");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_striteri());
}
