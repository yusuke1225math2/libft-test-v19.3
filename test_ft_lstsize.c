/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:39:33 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/04 01:21:08 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case1(const char *name)
{
	int	ok;

	ok = ft_lstsize(NULL) == 0;
	return (result(name, ok));
}

static int	test_case2(const char *name)
{
	int	ok;
	t_list	*head;
	t_list	*node1;

	node1 = ft_lstnew("a");
	head = node1;
	ok = ft_lstsize(head) == 1;
	free(node1);
	return (result(name, ok));
}

static int	test_case3(const char *name)
{
	int	ok;
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew("a");
	node2 = ft_lstnew("1");
	head = node1;
	ft_lstadd_front(&head, node2);
	ok = ft_lstsize(head) == 2;
	free(node1);
	free(node2);
	return (result(name, ok));
}

int	test_ft_lstsize(void)
{
	int	fail;

	printf("===== test_ft_lstsize =====\n");
	fail = 0;
	fail += test_case1("NULL");
	fail += test_case2("one node");
	fail += test_case3("two nodes");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstsize());
}
