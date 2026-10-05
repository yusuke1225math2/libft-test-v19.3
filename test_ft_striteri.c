/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:17:38 by yutambo          ###   ########.fr       */
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

static void	test_case(char *s, void (*f)(unsigned int, char*))
{
	printf("s     : \"%s\"\n", s);
	ft_striteri(s, f);
	printf("result: \"%s\"", s);
	printf("\n");
}

int	test_ft_striteri(void)
{
	int		fail;
	char	s1[] = "hello";
	char	s2[] = "abcdefghijk";
	char	s3[] = "01234567889";

	printf("===== test_ft_striteri =====\n");
	fail = 0;
	printf("\n==== Case: either s or f is NULL =====\n");
	test_case(NULL, idx_more_than_second);
	test_case(s1, NULL);
	printf("\n===== Case: idx_more_than_second =====\n");
	test_case(s3, idx_more_than_second);
	printf("\n===== Case: to_upper_even =====\n");
	test_case(s2, to_upper_even);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_striteri());
}
