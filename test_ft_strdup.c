/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:21:47 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/26 16:43:26 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#define TEST(s, f) test_func(#f, s, f)

static void	test_func(const char *fname, const char *s, char *(*f)(const char *))
{
	char	*d;

	printf("\n===== %s =====\n", fname);
	d = f(s);
	printf("s     : \"%s\"\n", s);
	printf("return: \"%s\"\n", d);
	free(d);
}

int	main(void)
{
	char	*src;

	src = "Silence is gold.";
	TEST(src, strdup);
	TEST(src, ft_strdup);
}
