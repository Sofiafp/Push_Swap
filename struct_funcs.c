/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:42:37 by salegre-          #+#    #+#             */
/*   Updated: 2022/02/20 20:07:40 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_stack	*create_new_node(int content)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (result == NULL)
		return (NULL);
	if (result)
	{
		result->content = content;
		result->next = NULL;
		result->prev = NULL;
	}
	return (result);
}

void	insert_at_head(t_stack **head, t_stack *new)
{
	if (!(*head) && new)
	{
		*head = new;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}
	else if (head && new)
	{
		(*head)->prev = new;
		new->next = *head;
		*head = (*head)->prev;
		(*head)->prev = NULL;
	}
}

void	remove_node(t_stack **head, t_stack *node_to_remove)
{
	if (*head == node_to_remove)
	{
		if ((*head)->next != NULL)
		{
			*head = node_to_remove->next;
			(*head)->prev = NULL;
		}
		else
			*head = NULL;
	}
	else
	{
		node_to_remove->next = node_to_remove->next;
		if (node_to_remove->next != NULL)
			node_to_remove->next->prev = node_to_remove->prev;
	}
	node_to_remove->next = NULL;
	node_to_remove->prev = NULL;
	free(node_to_remove);
}

void	clean_lst(t_stack **head_a)
{
	while (*head_a)
	{
		remove_node(&(*head_a), *head_a);
	}
}

t_stack	*get_tail(t_stack *head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}
