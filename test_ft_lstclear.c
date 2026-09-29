/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:28:04 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/29 21:26:27 by yutambo          ###   ########.fr       */
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
	int		ok;
	t_list	**lst;

	g_del_calls = 0;
	lst = NULL;
	ft_lstclear(lst, free_count);
	ok = (lst == NULL)
		&& (g_del_calls == 0);
	return (result(name, ok));
}

static int	test_case2(const char *name)
{
	int		ok;
	t_list	**lst;
	t_list	*head;

	g_del_calls = 0;
	head = NULL;
	lst = &head;
	ft_lstclear(lst, free_count);
	ok = (*lst == NULL)
		&& (g_del_calls == 0);
	return (result(name, ok));
}

static int	test_case3(const char *name)
{
	int		ok;
	t_list	**lst;
	t_list	*head;
	t_list	*node1;

	g_del_calls = 0;
	node1 = ft_lstnew(strdup("1"));
	head = node1;
	lst = &head;
	ft_lstclear(lst, free_count);
	ok = (*lst == NULL)
		&& (g_del_calls == 1);
	return (result(name, ok));
}

static int	test_case4(const char *name)
{
	int		ok;
	t_list	**lst;
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	g_del_calls = 0;
	node1 = ft_lstnew(strdup("1"));
	node2 = ft_lstnew(strdup("2"));
	node3 = ft_lstnew(strdup("3"));
	node2->next = node3;
	node1->next = node2;
	head = node1;
	lst = &head;
	ft_lstclear(lst, free_count);
	ok = (*lst == NULL)
		&& (g_del_calls == 3);
	return (result(name, ok));
}

static int	test_case5(const char *name)
{
	int		ok;
	t_list	**lst;
	t_list	*head;
	t_list	*node1;
	char	*s;

	g_del_calls = 0;
	s = strdup("1");
	node1 = ft_lstnew(s);
	head = node1;
	lst = &head;
	ft_lstclear(lst, NULL);
	ok = (*lst == NULL)
		&& (g_del_calls == 0);
	free(s);
	return (result(name, ok));
}

int	test_ft_lstclear(void)
{
	int	fail;

	fail = 0;
	fail += test_case1("lst==NULL");
	fail += test_case2("*lst==NULL");
	fail += test_case3("1 node list");
	fail += test_case4("3 nodes list");
	fail += test_case5("del==NULL");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstclear());
}
