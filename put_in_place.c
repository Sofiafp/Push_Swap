/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:46:12 by salegre-          #+#    #+#             */
/*   Updated: 2022/02/20 20:05:16 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_stack	*rotate_it(t_stack *head, int count)
{
	if (lst_size(head) == count)
		return (head);
	count++;
	if (count > lst_size(head) / 2)
	{
		count = lst_size(head) - count + 1;
		while (count--)
			rra_rrb(&(head), 1);
	}
	else
	{
		while (count--)
			ra_rb(&(head), 1);
	}
	return (head);
}

//checkar o valgrind desta merdaria
int	morrer_e_melhor(t_stack *head_a, int val)
{
	t_stack	*node;

	node = create_new_node(val);
	insert_at_head(&head_a, node);
	if (is_it_ordered(head_a))
	{
		head_a = head_a->next;
		head_a->prev = NULL;
		free(node);
		return (1);
	}
	if (is_it_semi_ordered(head_a))
	{
		head_a = head_a->next;
		head_a->prev = NULL;
		free(node);
		return (1);
	}
	head_a = head_a->next;
	head_a->prev = NULL;
	free(node);
	return (0);
}

int	smlst_or_bigst(t_stack *head, int val)
{
	while (head->next != NULL)
	{
		if (head->content > head->next->content)
			break ;
		head = head->next;
	}
	if (head->next != NULL)
		if (val > head->content || val < head->next->content)
			return (1);
	return (0);
}

int	find_spot_do_min_max(t_stack *head)
{
	int	i;

	i = 0;
	while (head->next != NULL)
	{
		if (head->content > head->next->content)
			break ;
		i++;
		head = head->next;
	}
	return (i);
}

int	find_the_place(t_stack *head, int val)
{
	int		index;
	t_stack	*lst;
	t_stack	*lst_abs;

	lst = NULL;
	lst_abs = NULL;
	if (morrer_e_melhor(head, val))
		return (-1);
	if (smlst_or_bigst(head, val))
		return (find_spot_do_min_max(head));
	create_dif_lst(&lst, head, val);
	create_abs_lst(&lst_abs, lst);
	index = find_the_smalest(lst_abs, lst);
	clean_lst(&lst);
	clean_lst(&lst_abs);
	return (index);
}
