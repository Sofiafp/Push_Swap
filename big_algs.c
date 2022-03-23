/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:00:06 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/22 16:27:54 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_stack	*smallest_no(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (head->next != NULL)
	{
		if (tmp->content > head->content)
			tmp = head;
		head = head->next;
	}
	if (tmp->content > head->content)
		tmp = head;
	return (tmp);
}

int	no_more_quartile(t_stack *head, int bigg)
{
	while (head->next != NULL)
	{
		if (head->content > bigg)
			return (1);
		head = head->next;
	}
	if (head->content > bigg)
		return (1);
	return (0);
}

void	iterate_quartiles(t_stack **head_a, t_stack **head_b, int bigg)
{
	while (lst_size(*head_a) != 3 && no_more_quartile(*head_a,bigg))
	{
		if ((*head_a)->content > bigg)
			pa_pb(&(*head_a), &(*head_b), 0);
		else
			ra_rb(&(*head_a), 1);
	}	
}

void	put_it_on_b(t_stack **head_a, t_stack **head_b)
{
	int	bigg;
	int	small;
	int	quarter;

	bigg = find_the_biggest(*head_a)->content;
	small = smallest_no(*head_a)->content;
	quarter = (bigg - small) / 6;
	bigg = bigg - quarter;
	iterate_quartiles(&(*head_a), &(*head_b), bigg);
	bigg = bigg - quarter;
	iterate_quartiles(&(*head_a), &(*head_b), bigg);
	bigg = bigg - quarter;
	iterate_quartiles(&(*head_a), &(*head_b), bigg);
	bigg = bigg - quarter;
	iterate_quartiles(&(*head_a), &(*head_b), bigg);
	bigg = bigg - quarter;
	iterate_quartiles(&(*head_a), &(*head_b), bigg);
	while (!is_it_ordered(*head_a) && lst_size(*head_a) != 3)
		pa_pb(&(*head_a), &(*head_b), 0);
	pa_pb(&(*head_a), &(*head_b), 0);
	*head_a = three_als(*head_a);
}

t_stack	*big_alg(t_stack *head_a)
{
	t_stack	*head_b;
	t_stack	*node_to_put;

	head_b = NULL;
	if (is_it_semi_ordered(head_a))
		return (rotate_to_order(head_a));
	put_it_on_b(&head_a, &head_b);
	while (head_b->next != NULL)
	{
		node_to_put = chose_what_to_do(head_a, head_b);
		and_do_it(&(head_a), &(head_b), node_to_put);
		pa_pb(&(head_b), &(head_a), 1);
		printlist(head_a, 2);
		printlist(head_b, 2);	
	}
	head_a = rotate_it(head_a, find_the_place(head_a, head_b->content));
	pa_pb(&(head_b), &(head_a), 1);
	head_a = rotate_to_order(head_a);
	printlist(head_a, 3);
	printlist(head_b, 3);
	clean_lst(&head_b);
	return (head_a);
}
