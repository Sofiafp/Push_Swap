/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:40:14 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/22 10:01:57 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
//APAGAR DEPOIS
void	printlist(t_stack *head, int color)
{
	(void)color;
	(void)head;
	
	// if (head && color == 1)
	// {
	// 	while (head->next != NULL)
	// 	{
	// 		printf("\033[36;1m%d | \033[0m", head->content);
	// 		head = head->next;
	// 	}
	// 	if (head != NULL)
	// 		printf("\033[36;1m%d | \033[0m", head->content);
	// }
	// if (head && color == 0)
	// {
	// 	while (head->next != NULL)
	// 	{
	// 		printf("\033[0;35m%d | \033[0m", head->content);
	// 		head = head->next;
	// 	}
	// 	if (head != NULL)
	// 		printf("\033[0;35m%d | \033[0m", head->content);
	// }
	// if (head && color == 2)
	// {
	// 	while (head->next != NULL)
	// 	{
	// 		printf("\e[0;32m%d | \e[0m", head->content);
	// 		head = head->next;
	// 	}
	// 	if (head != NULL)
	// 		printf("\e[0;32m%d | \e[0m", head->content);
	// }
	// printf("\n ~~~~~~~~~~~~~~ \n");
}

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
	printlist(head_a, 1);
	clean_lst(&head_a);
	return (0);
}
