/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 21:33:50 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/05 23:53:23 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	f_count;

static void	print_count(void *content)
{
	f_count++;
	printf("%s\n", (char *)content);
}

static int	test_case1(const char *name)
{
	int	ok;

	f_count = 0;
	ft_lstiter(NULL, print_count);
	ok = (f_count == 0);
	return (result(name, ok));
}

static int	test_case2(const char *name)
{
	int		ok;
	t_list	*node1;
	t_list	*head;
	t_list	**lst;

	f_count = 0;
	node1 = ft_lstnew(strdup("node1"));
	head = node1;
	ft_lstiter(node1, NULL);
	ok = (f_count == 0);
	lst = &head;
	ft_lstclear(lst, free);
	return (result(name, ok));
}

static int	test_case3(const char *name)
{
	int		ok;
	t_list	*node1;
	t_list	*head;
	t_list	**lst;

	f_count = 0;
	node1 = ft_lstnew(strdup("node1"));
	head = node1;
	ft_lstiter(node1, print_count);
	ok = (f_count == 1);
	lst = &head;
	ft_lstclear(lst, free);
	return (result(name, ok));
}

static int	test_case4(const char *name)
{
	int		ok;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*head;
	t_list	**lst;

	f_count = 0;
	node1 = ft_lstnew(strdup("node1"));
	node2 = ft_lstnew(strdup("node2"));
	node3 = ft_lstnew(strdup("node3"));
	head = node1;
	node1->next = node2;
	node2->next = node3;
	ft_lstiter(node1, print_count);
	ok = (f_count == 3);
	lst = &head;
	ft_lstclear(lst, free);
	return (result(name, ok));
}

int	test_ft_lstiter(void)
{
	int	fail;

	printf("===== test_ft_lstiter =====\n");
	fail = 0;
	fail += test_case1("lst==NULL");
	fail += test_case2("f==NULL");
	fail += test_case3("lst has 1 node");
	fail += test_case4("lst has 3 nodes");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstiter());
}
