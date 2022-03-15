/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_what_to_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:41:41 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/15 19:36:48 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	chose_aux(t_stack *places)
{
	int	len_p;
	int i;
	
	len_p = lst_size(places) + 1;
	i = 0;
	while(places != NULL)
	{
		if (i <= len_p/2 && places->content <= len_p/2)
		{
			if ( i <= places->content)
				places->content = places->content;
			else
				places->content = i;
		}
		else
		{
			if ( i <= places->content)
				places->content = len_p - places->content + 1;
			else
				places->content = len_p - i + 1;	
		}
		i++;
		if (places->next != NULL)
			places = places->next;
		else
			break;
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

void	move_small(t_stack *places)
{
	int	len_p;
	int i;
	
	len_p = lst_size(places);
	i = 0;

	if (i <= len_p/2 && places->content <= len_p/2)
	{
		if ( i <= places->content)
			places->content = places->content;
		else
			places->content = i;
	}
	else
	{
		if ( i <= places->content)
			places->content = len_p - places->content + 1;
		else
			places->content = len_p - i + 1;	
	}
	i++;
	if (places->next != NULL)
		places = places->next;
	// else
	// 	break ;
}

t_stack *chose_what_to_do(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tail;
	t_stack	*places;
	t_stack *small;
	int j;
	
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
	int i;
	i = 2;
	chose_aux(places);
//	int count = 0;
	small = smallest_no(places);
	t_stack	*tmp;

	tmp = places;
	while (tmp != small && head_b->next != NULL &&  tmp->next != NULL)
	{
		head_b = head_b->next;
		tmp = tmp->next;
	}
	clean_lst(&places);
	return (head_b);
}
