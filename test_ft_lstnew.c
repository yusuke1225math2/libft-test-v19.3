/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutambo <yutambo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:42:52 by yutambo           #+#    #+#             */
/*   Updated: 2026/09/29 13:46:31 by yutambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_case(const char *name, void *content)
{
	int		ok;
	t_list	*node;

	node = ft_lstnew(content);
	ok = (node->content == content) && (node->next == NULL);
	free(node);
	return (result(name, ok));
}

int	test_ft_lstnew(void)
{
	int	fail;
	int	arr[3] = {1, 2, 3};

	fail = 0;
	fail += test_case("normal string", "abc");
	fail += test_case("normal int arr", arr);
	fail += test_case("NULL content", NULL);
	result_all(fail);
	return (fail != 0);
}

int	main(void)
{
	return (test_ft_lstnew());
}
