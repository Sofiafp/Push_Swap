/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:00:06 by salegre-          #+#    #+#             */
/*   Updated: 2022/02/18 12:24:41 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	two_algs_rev(t_stack **head_a, t_stack **head_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (*head_b != NULL && (*head_b)->next != NULL)
		if ((*head_b)->content < (*head_b)->next->content)
			b = 1;
	if (head_a != NULL && (*head_a)->next != NULL)
		if ((*head_a)->content > (*head_a)->next->content)
			a = 1;
	if (a && b)
	{
		ft_putstr_fd("ss\n", 1);
		sa_sb(&(*head_a), -1);
		sa_sb(&(*head_b), -1);
	}
//	else if (a)
//		sa_sb(&(*head_a), 1);
	else if (b)
		sa_sb(&(*head_b), 0);
}

void	put_it_on_b(t_stack **head_a, t_stack **head_b)
{
	while (!is_it_ordered(*head_a) && lst_size(*head_a) != 3)
	{
		if ((*head_a)->content > (*head_a)->next->content)
		{
			if (get_tail(*head_a)->content > (*head_a)->next->content)
				ra_rb(&(*head_a), 1);
			else
				rra_rrb(&(*head_a), 1);
		}
		else
			pa_pb(&(*head_a), &(*head_b), 0);
		if (is_it_semi_ordered(*head_a))
			*head_a = rotate_to_order(*head_a);
		else if (*head_a != NULL && *head_b != NULL)
			two_algs_rev(&(*head_a), &(*head_b));
		printlist(*head_a, 1);
		printlist(*head_b, 1);
	}
	pa_pb(&(*head_a), &(*head_b), 0);
	*head_a = three_als(*head_a);
}

t_stack	*big_alg(t_stack *head_a)
{
	t_stack	*head_b;
	int		j;

	head_b = NULL;

	if (is_it_semi_ordered(head_a))
		return (rotate_to_order(head_a));
	put_it_on_b(&head_a, &head_b);
	j = 0;
	while (head_b != NULL)
	{
		printlist(head_a, 1);
		printlist(head_b, 1);
		j = find_the_place(head_a, head_b->content);
		//printf("index: %d\n", j);
		head_a = rotate_it(head_a, j);
		pa_pb(&head_b, &head_a, 1);
	}
	if (!is_it_ordered(head_a))
		head_a = rotate_to_order(head_a);
	printlist(head_a, 1);
	printlist(head_b, 1);
	clean_lst(&head_b);
	return (head_a);
}
