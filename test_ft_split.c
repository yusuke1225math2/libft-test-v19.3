/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/06 23:25:10 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	cmp_split(char **r, const char *const *exp)
{
	size_t	i;

	if (!r || !exp)
		return (!r && !exp);
	i = 0;
	while (r[i] && exp[i])
	{
		if (strcmp(r[i], exp[i]) != 0)
			return (0);
		i++;
	}
	return (r[i] == NULL && exp[i] == NULL);
}

static void	free_split(char **r)
{
	size_t	i;

	i = 0;
	while (r && r[i])
	{
		free(r[i]);
		i++;
	}
	free(r);
}

static int	test_case(const char *name, char const *s, char c,
						const char *const *exp)
{
	char	**r;
	int		ok;

	r = ft_split(s, c);
	ok = cmp_split(r, exp);
	free_split(r);
	return (result(name, ok));
}

int	test_ft_split(void)
{
	int					fail;
	const char *const	exp_empty[] = {NULL};
	const char *const	exp_one[] = {"abc", NULL};
	const char *const	exp_three[] = {"aaa", "bb", "c", NULL};
	const char *const	exp_multi[] = {"aaa", "b", "c", "dddd", "e", NULL};
	const char *const	exp_words[] = {"hello", "world", NULL};

	printf("===== test_ft_split =====\n");
	fail = 0;
	fail += test_case("NULL s", NULL, '.', NULL);
	fail += test_case("empty s", "", '.', exp_empty);
	fail += test_case("only seps", "...", '.', exp_empty);
	fail += test_case("s == sep", "a", 'a', exp_empty);
	fail += test_case("no sep", "abc", '.', exp_one);
	fail += test_case("multi", "aaa.b.c.dddd.e", '.', exp_multi);
	fail += test_case("leading", "..aaa.bb.c", '.', exp_three);
	fail += test_case("consecutive", "aaa...bb.c.", '.', exp_three);
	fail += test_case("leand and trail", "..aaa.bb.c.", '.', exp_three);
	fail += test_case("spaces", "  hello   world  ", ' ', exp_words);
	fail += test_case("sep is NUL", "abc", '\0', exp_one);
	result_all(fail);
	return (fail);
}

int	main(void)
{
	return (test_ft_split());
}
