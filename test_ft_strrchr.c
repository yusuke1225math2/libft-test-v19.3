/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 00:30:17 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/07 00:43:57 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, const char *s, int c)
{
	char	*ra;
	char	*rb;

	ra = strrchr(s, c);
	rb = ft_strrchr(s, c);
	//printf("\nra: [%s]\nrb: [%s]\n", ra, rb);
	return (result(name, ra == rb));
}

int	test_ft_strrchr(void)
{
	int	fail;

	printf("===== test_ft_strrchr =====\n");
	fail = 0;
	fail += test_case("repeated", "ABCABC", 'A');
	fail += test_case("repeated end", "ABCABC", 'C');
	fail += test_case("once", "ABC", 'B');
	fail += test_case("single", "a", 'a');
	fail += test_case("not found", "ABCABC", 'z');
	fail += test_case("nul", "ABCABC", '\0');
	fail += test_case("empty nul", "", '\0');
	fail += test_case("empty a", "", 'a');
	fail += test_case("c+256", "ABCABC", 'B' + 256);
	fail += test_case("256 -> nul", "ABCABC", 256);
	fail += test_case("high byte", "A\xe9" "B\xe9", 0xe9);
	fail += test_case("negative byte", "A\xe9" "B\xe9", -23);
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_strrchr());
}
