/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/26 18:43:33 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"



static void	test_case(char const *s, char c)
{
	char	**result;
	char	**r;

	result = ft_split(s, c);
	r = result;
	printf("----------\n");
	printf("s: \"%s\"\n", s);
	printf("c: \'%c\'\n", c);
	printf("return:\n");
	while (r && *r)
	{
		printf("  \"%s\"\n", *r);
		free(*r);
		r++;
	}
	if (result)
		free(result);
}

int	main(void)
{
	test_case(NULL, '.');
	test_case("aaa.b.c.dddd.e", '.');
	test_case("..aaa.bb.", '.');
	test_case("aaa..bb.c.", '.');
	test_case(".aaa..bb.c.", '.');
	test_case("...", '.');
	test_case("", '.');
}

