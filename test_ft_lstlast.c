/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:00:23 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/05 23:53:46 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case1(const char *name)
{
	int	ok;

	ok = ft_lstlast(NULL) == NULL;
	return (result(name, ok));
}

static int	test_case2(const char *name)
{
	int		ok;
	t_list	*head;
	t_list	*node1;

	node1 = ft_lstnew("");
	head = node1;
	ok = ft_lstlast(head) == node1;
	free(node1);
	return (result(name, ok));
}

static int	test_case3(const char *name)
{
	int		ok;
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("");
	node2 = ft_lstnew("a");
	node3 = ft_lstnew("1");
	head = node3;
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	ok = ft_lstlast(head) == node3;
	free(node1);
	free(node2);
	free(node3);
	return (result(name, ok));
}

int	test_ft_lstlast(void)
{
	int	fail;

	printf("===== test_ft_lstlast =====\n");
	fail = 0;
	fail += test_case1("NULL");
	fail += test_case2("single node");
	fail += test_case3("three nodes");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstlast());
}
