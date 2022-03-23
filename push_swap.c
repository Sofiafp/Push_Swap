/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:40:14 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/23 13:17:01 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_stack	*what_size(t_stack *head, int nargs)
{
	if (nargs == 2)
		return (two_algs(head));
	if (nargs == 3)
		return (three_als(head));
	return (big_alg(head));
}

int	push_swap(int argc, char **argv)
{
	t_stack	*node;
	t_stack	*head_a;
	int		nargs;

	head_a = NULL;
	nargs = argc - 1;
	while (argc != 1)
	{
		if (is_it_num(argv[--argc]) == 0)
			return (error_msg(&head_a));
		node = create_new_node(ft_atoi(argv[argc]));
		insert_at_head(&head_a, node);
	}
	if (does_it_repeat(head_a))
		return (error_msg(&head_a));
	if (!is_it_ordered(head_a))
	{
		head_a = what_size(head_a, nargs);
	}
	clean_lst(&head_a);
	return (0);
}
