/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:17:40 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/29 17:40:50 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case1(const char *name)
{
	int		ok;
	t_list	*new;

	new = ft_lstnew("new");
	ft_lstadd_back(NULL, new);
	ok = new->next == NULL;
	free(new);
	return (result(name, ok));
}

static int	test_case2(const char *name)
{
	int		ok;
	t_list	*head;
	t_list	*node;

	node = ft_lstnew("node");
	head = node;
	ft_lstadd_back(&head, NULL);
	ok = (head && head == node && head->next == NULL);
	free(node);
	return (result(name, ok));
}

static int	test_case3(const char *name)
{
	int		ok;
	t_list	*head;
	t_list	*new;

	new = ft_lstnew("new");
	head = NULL;
	ft_lstadd_back(&head, new);
	ok = (head && head == new && head->next == NULL);
	free(new);
	return (result(name, ok));
}

static int	test_case4(const char *name)
{
	int		ok;
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*new;

	node1 = ft_lstnew("node1");
	node2 = ft_lstnew("node2");
	new = ft_lstnew("new");
	head = node1;
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, new);
	ok = (head == node1 && ft_lstlast(head) == new && node1->next == node2);
	free(node1);
	free(node2);
	free(new);
	return (result(name, ok));
}

int	test_ft_lstadd_back(void)
{
	int	fail;

	fail = 0;
	fail += test_case1("lst is NULL");
	fail += test_case2("new is NULL");
	fail += test_case3("add to empty list");
	fail += test_case4("add to normal list");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstadd_back());
}
