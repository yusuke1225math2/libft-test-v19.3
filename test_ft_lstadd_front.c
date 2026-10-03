/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/04 01:19:11 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case1(const char *name)
{
	int	ok;
	t_list	*head;
	t_list	*new;

	head = NULL;
	new = ft_lstnew("abc");
	ft_lstadd_front(&head, new);
	ok = (head == new) && (head->next == NULL);
	free(new);
	return (result(name, ok));
}

static int	test_case2(const char *name)
{
	int	ok;
	t_list	*head;
	t_list	*node;
	t_list	*new;

	node = ft_lstnew("012");
	head = node;
	new = ft_lstnew("abc");
	ft_lstadd_front(&head, new);
	ok = (head == new) && (head->next == node);
	free(new);
	free(node);
	return (result(name, ok));
}

static int	test_case3(const char *name)
{
	t_list	*new;

	new = ft_lstnew("abc");
	ft_lstadd_front(NULL, new);
	free(new);
	return (result(name, 1));
}

static int	test_case4(const char *name)
{
	int		ok;
	t_list	*head;
	t_list	*node;

	node = ft_lstnew("012");
	head = node;
	ft_lstadd_front(&head, NULL);
	ok = (head == node) && (node->next == NULL);
	free(node);
	return (result(name, ok));
}

int	test_ft_lstadd_front(void)
{
	int		fail;

	printf("===== test_ft_lstadd_front =====\n");
	fail = 0;
	fail += test_case1("empty lst");
	fail += test_case2("normal lst");
	fail += test_case3("NULL lst");
	fail += test_case4("NULL new");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstadd_front());
}
