/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_what_to_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:41:41 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/22 17:09:56 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	chose_aux_aux(t_stack *places, int i, int len_p, int len_a)
{
	if (i <= len_p / 2 && places->content <= len_a / 2)
	{
		if (i <= places->content)
			places->content = places->content;
		else
			places->content = i;
	}
	else if (i > len_p / 2 && places->content > len_a / 2)
	{
		if (i <= places->content)
			places->content = len_a - places->content + 1;
		else
			places->content = len_p - i + 1;
	}
	else if (places->content > len_a / 2 && i <= len_p / 2)
		places->content = i + len_a - places->content;
	else if (places->content <= len_a / 2 && i > len_p / 2)
		places->content = len_p - i + places->content;
	else
		places->content = places->content + i;
}

void	chose_aux(t_stack *places, t_stack *head_a)
{
	int	len_p;
	int	len_a;
	int	i;

	len_p = lst_size(places) + 1;
	len_a = lst_size(head_a) + 1;
	i = 0;
	while (places != NULL)
	{
		chose_aux_aux(places, i, len_p, len_a);
		i++;
		if (places->next != NULL)
			places = places->next;
		else
			break ;
	}
}

t_stack	*iterate_to_smallest(t_stack *head, int *count)
{
	t_stack	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (head->next != NULL)
	{
		if (tmp->content > head->content)
		{
			tmp = head;
			*count = i;
		}
		head = head->next;
		i++;
	}
	if (tmp->content > head->content)
	{
		tmp = head;
		*count = i;
	}
	return (tmp);
}

t_stack	*chose_what_to_do(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tail;
	t_stack	*places;
	t_stack	*small;
	int		j;

	tail = get_tail(head_b);
	places = NULL;
	j = 0;
	while (tail->prev != NULL)
	{
		j = find_the_place(head_a, tail->content);
		insert_at_head(&places, create_new_node(j + 1));
		tail = tail->prev;
	}
	j = find_the_place(head_a, tail->content);
	insert_at_head(&places, create_new_node(j + 1));
	chose_aux(places, head_a);
	small = smallest_no(places);
	while (places != small && head_b->next != NULL && places->next != NULL)
	{
		head_b = head_b->next;
		places = places->next;
	}
	clean_lst(&places);
	return (head_b);
}
