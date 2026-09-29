/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:53:40 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/29 18:16:25 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	g_del_calls;

static void	free_count(void *p)
{
	g_del_calls++;
	free(p);
}

static int	test_case1(const char *name)
{
	int	ok;

	g_del_calls = 0;
	ft_lstdelone(NULL, free_count);
	ok = g_del_calls == 0;
	return (result(name, ok));
}

static int	test_case2(const char *name)
{
	int	ok;
	t_list	*node1;
	t_list	*node2;

	g_del_calls = 0;
	node1 = ft_lstnew(strdup("node1"));
	node2 = ft_lstnew("node2");
	node1->next = node2;
	ft_lstdelone(node1, free_count);
	ok = (g_del_calls == 1) && strcmp(node2->content, "node2") == 0
		&& node2->next == NULL;
	free(node2);
	return (result(name, ok));
}

int	test_ft_lstdelone(void)
{
	int	fail;

	fail = 0;
	fail += test_case1("lst is NULL");
	fail += test_case2("del node1 of two nodes");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstdelone());
}
