/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:28:57 by yutambo          ###   ########.fr       */
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

static void	test_case(char const *s, char (*f)(unsigned int, char))
{
	char	*r;

	r = ft_strmapi(s, f);
	printf("s: \"%s\", return: \"%s\"", s, r);
	printf("\n");
	free(r);
}

int	test_ft_strmapi(void)
{
	int	fail;

	printf("===== test_ft_strmapi =====\n");
	fail = 0;
	printf("\n==== Case: either s or f is NULL =====\n");
	test_case(NULL, idx_more_than_second);
	test_case("hello", NULL);
	printf("\n===== Case: idx_more_than_second =====\n");
	test_case("012345", idx_more_than_second);
	printf("\n===== Case: to_upper_even =====\n");
	test_case("abcdef", to_upper_even);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strmapi());
}
