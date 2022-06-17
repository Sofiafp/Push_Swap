/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_alg_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:36:34 by salegre-          #+#    #+#             */
/*   Updated: 2022/04/28 15:51:05 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	is_it_bigger(t_stack *a, t_stack *b)
{
	if (b == NULL)
		return (0);
	if (a->content > b->content)
		return (1);
	return (0);
}

int	lst_size(t_stack *head)
{
	int	i;

	i = 0;
	while (head->next != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

t_stack	*find_the_biggest(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (head->next != NULL)
	{
		if (tmp->content < head->content)
			tmp = head;
		head = head->next;
	}
	if (tmp->content < head->content)
		tmp = head;
	return (tmp);
}

int	is_it_semi_ordered(t_stack *head)
{
	t_stack	*bgst;
	t_stack	*tail;

	bgst = find_the_biggest(head);
	tail = get_tail(head);
	while (bgst->prev != NULL)
	{
		if (bgst->content < bgst->prev->content)
			return (0);
		bgst = bgst->prev;
	}
	if (tail->content > head->content)
		return (0);
	while (tail->prev != find_the_biggest(head))
	{
		if (tail->content < tail->prev->content)
			return (0);
		tail = tail->prev;
	}
	return (1);
}

t_stack	*rotate_to_order(t_stack *head)
{
	t_stack	*bgst;
	t_stack	*tmp;
	int		count;

	bgst = find_the_biggest(head);
	count = 1;
	tmp = head;
	while (tmp != bgst)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > lst_size(head) / 2)
	{
		count = lst_size(head) - count + 1;
		while (count--)
			rra_rrb(&head, 1);
	}
	else
	{
		while (count--)
			ra_rb(&head, 1);
	}
	return (head);
}
