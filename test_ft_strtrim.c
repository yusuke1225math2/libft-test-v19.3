/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/26 13:21:27 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

void	test_case(char const *s1, char const *set)
{
	char	*r;

	r = ft_strtrim(s1, set);
	printf("s1: \"%s\", set: \"%s\", return: \"%s\"", s1, set, r);
	printf("\n");
	free(r);
}

int	main(void)
{
	char	*s1;

	printf("===== Case: s1 or set is NULL=====\n");
	s1 = NULL;
	test_case(s1, " ");
	test_case("abc", NULL);
	printf("\n");
	printf("===== Case: s1 is empty =====\n");
	test_case("", "xyz");
	printf("\n");
	printf("===== Case: s1 consists of set =====\n");
	test_case("xxyzyzxx", "xyz");
	printf("\n");
	printf("===== Case: s1 should be trimmed =====\n");
	test_case("yyxxzzABCDEFxyzxyz", "xyz");
	printf("\n");
	printf("===== Case: s1 should not be trimmed =====\n");
	test_case("AxByCzD", "xyz");
}
