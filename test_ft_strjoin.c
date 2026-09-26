/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/26 17:51:36 by yutambo          ###   ########.fr       */
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

int	main(void)
{
	test_case("123", NULL);
	test_case(NULL, "4567");
	test_case(NULL, NULL);
	test_case("", "");
	test_case("123", "");
	test_case("", "4567");
	test_case("123", "4567");
}
