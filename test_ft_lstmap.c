/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 11:55:07 by yutambo           #+#    #+#             */
/*   Updated: 2026/10/04 01:35:14 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// To run this test, run following command.
// ccw tests/utils.c tests/test_ft_lstmap.c libft.a -Wl,--wrap=ft_lstnew && ./a.out

#include "test_libft.h"

static int	del_calls;
static int	new_calls;
static int	fail_on;
static int	f_calls;

t_list	*__real_ft_lstnew(void *content);

t_list	*__wrap_ft_lstnew(void *content)
{
	new_calls++;
	if (new_calls == fail_on)
		return (NULL);
	return (__real_ft_lstnew(content));
}

static void	*f(void *s)
{
	char	*content;
	size_t	i;

	f_calls++;
	content = strdup(s);
	if (!content)
		return (NULL);
	i = 0;
	while (content[i])
	{
		content[i] = toupper(content[i]);
		i++;
	}
	return (content);
}

static void	del(void *s)
{
	del_calls++;
	free(s);
}

static int	test_case1(const char *name)
{
	int		ok;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new;

	node1 = ft_lstnew(strdup("abc"));
	node2 = ft_lstnew(strdup("def"));
	node3 = ft_lstnew(strdup("012"));
	node1->next = node2;
	node2->next = node3;
	del_calls = 0;
	new = ft_lstmap(node1, f, del);
	ok = (del_calls == 0)
		&& (new != NULL)
		&& (strcmp(new->content, "ABC") == 0)
		&& (strcmp(new->next->content, "DEF") == 0)
		&& (strcmp(new->next->next->content, "012") == 0)
		&& (new->next->next->next == NULL);
	ft_lstclear(&new, del);
	ft_lstclear(&node1, del);
	return (result(name, ok));
}

static int	test_case2(const char *name)
{
	int		ok;
	t_list	*node;
	t_list	*new;

	node = ft_lstnew(strdup("node"));
	new = ft_lstmap(node, f, del);
	ok = (new != NULL)
		&& (strcmp(new->content, "NODE") == 0)
		&& (new->next == NULL);
	ft_lstclear(&new, del);
	ft_lstclear(&node, del);
	return (result(name, ok));
}

static int	test_case3(const char *name)
{
	int		ok;
	t_list	*new;

	new = ft_lstmap(NULL, f, del);
	ok = new == NULL;
	return (result(name, ok));
}

static int	test_case4(const char *name)
{
	int		ok;
	t_list	*node;
	t_list	*new;

	node = ft_lstnew(strdup("node"));
	new = ft_lstmap(node, NULL, del);
	ok = new == NULL;
	ft_lstclear(&node, del);
	return (result(name, ok));
}

static int	test_case5(const char *name)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new;
	int		ok;

	node1 = ft_lstnew(strdup("abc"));
	node2 = ft_lstnew(strdup("def"));
	node3 = ft_lstnew(strdup("012"));
	node1->next = node2;
	node2->next = node3;
	del_calls = 0;
	new_calls = 0;
	f_calls = 0;
	fail_on = 1;
	new = ft_lstmap(node1, f, del);
	ok = (new == NULL)
		&& (del_calls == fail_on)
		&& (f_calls == fail_on);
	ft_lstclear(&node1, del);
	return (result(name, ok));
	
}

int	test_ft_lstmap(void)
{
	int	fail;

	printf("===== test_ft_lstmap =====\n");
	fail = 0;
	fail += test_case1("3 nodes");
	fail += test_case2("1 node");
	fail += test_case3("empty list");
	fail += test_case4("f==NULL");
	fail += test_case5("ft_lstnew fail");
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstmap());
}
