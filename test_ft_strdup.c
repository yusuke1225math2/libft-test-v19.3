/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:21:47 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/04 01:41:43 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, const char *s)
{
	int	ok;
	char	*ra;
	char	*rb;

	ra = strdup(s);
	rb = ft_strdup(s);
	ok = strcmp(ra, rb) == 0;
	free(ra);
	free(rb);
	return (result(name, ok));
}

int	test_ft_strdup(void)
{
	int	fail = 0;

	printf("===== test_ft_strdup =====\n");
	fail += test_case("\"\"", "");
	fail += test_case("\"Silence is gold.\"", "Silence is gold.");
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_strdup());
}
