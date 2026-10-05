/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 00:19:04 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void	test_case(char const *s1, char const *s2)
{
	char	*r;

	r = ft_strjoin(s1, s2);
	printf("s1: \"%s\", s2: \"%s\", return: \"%s\"\n", s1, s2, r);
	free(r);
}

int	test_ft_strjoin(void)
{
	int	fail;

	printf("===== test_ft_strjoin =====\n");
	fail = 0;
	test_case("123", NULL);
	test_case(NULL, "4567");
	test_case(NULL, NULL);
	test_case("", "");
	test_case("123", "");
	test_case("", "4567");
	test_case("123", "4567");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strjoin());
}
