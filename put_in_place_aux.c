/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_place_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:02:37 by salegre-          #+#    #+#             */
/*   Updated: 2022/02/20 20:03:15 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	create_dif_lst(t_stack	**lst, t_stack *head, int val)
{
	t_stack	*node;
	t_stack	*tail;

	tail = get_tail(head);
	while (tail->prev != NULL)
	{
		node = create_new_node(tail->content - val);
		insert_at_head(&(*lst), node);
		tail = tail->prev;
	}
	node = create_new_node(tail->content - val);
	insert_at_head(&(*lst), node);
}

void	create_abs_lst(t_stack **lst_abs, t_stack *head)
{
	t_stack	*node;
	t_stack	*tail;

	tail = get_tail(head);
	while (tail->prev != NULL)
	{
		if (tail->content < 0)
			node = create_new_node(tail->content * (-1));
		else
			node = create_new_node(tail->content);
		insert_at_head(&(*lst_abs), node);
		tail = tail->prev;
	}	
	if (tail->content < 0)
		node = create_new_node(tail->content * (-1));
	else
		node = create_new_node(tail->content);
	insert_at_head(&(*lst_abs), node);
}

int	find_the_smallest_aux(t_stack *lst_w_negs, int i)
{
	if (lst_w_negs->prev != NULL )
	{
		if (lst_w_negs->content < 0)
		{
			if (lst_w_negs->prev->content > 0 && lst_w_negs->next != NULL && lst_w_negs->next->content < 0)
				return (i - 1);
			if (lst_w_negs->next == NULL) 
				return (i - 1);
		}
		else
			if (lst_w_negs->prev->content < 0 && lst_w_negs->next != NULL && lst_w_negs->next->content > 0)
				return (i - 1);
			if (lst_w_negs->next == NULL) 
				return (i - 1);
			if (lst_w_negs->prev->content < 0 && lst_w_negs->next != NULL && lst_w_negs->next->content < 0)
				return (i - 1);
			
	}
	return (i);
}

int	find_the_smalest(t_stack *lst, t_stack *lst_w_negs)
{
	t_stack	*small;
	t_stack	*tmp;
	int		i;

	i = 0;
	small = lst;
	tmp = lst;
	while (lst->next != NULL)
	{
		if (small->content > lst->content)
			small = lst;
		lst = lst->next;
	}
	if (small->content > lst->content)
		small = lst;
	while (tmp != small)
	{
		lst_w_negs = lst_w_negs->next;
		tmp = tmp->next;
		i++;
	}
	return (find_the_smallest_aux(lst_w_negs, i));
}
