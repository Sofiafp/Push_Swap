/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:07:10 by salegre-          #+#    #+#             */
/*   Updated: 2022/02/17 18:02:10 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ra_rb(t_stack **head, int a_or_b)
{
	t_stack	*tmp;
	t_stack	*tail;

	if ((*head)->next != NULL)
	{
		tail = get_tail(*head);
		tmp = (*head);
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		tail->next = tmp;
		tmp->next = NULL;
		tmp->prev = tail;
		if (a_or_b == 1)
			ft_putstr_fd("ra\n", 1);
		if (a_or_b == 0)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rra_rrb(t_stack **head, int a_or_b)
{
	t_stack	*tmp;
	t_stack	*tail;

	if ((*head)->next != NULL)
	{
		tail = get_tail(*head)->prev;
		tmp = get_tail(*head);
		tail->next = NULL;
		tmp->next = *head;
		(*head)->prev = tmp;
		tmp->prev = NULL;
		(*head) = (*head)->prev;
		if (a_or_b == 1)
			ft_putstr_fd("rra\n", 1);
		if (a_or_b == 0)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	pa_pb(t_stack **head_a, t_stack**head_b, int a_or_b)
{
	t_stack	*tmp;

	tmp = *head_a;
	if ((*head_a)->next != NULL)
	{
		*head_a = (*head_a)->next;
		(*head_a)->prev = NULL;
	}
	else
		*head_a = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	insert_at_head(&(*head_b), tmp);
	if (a_or_b == 1)
		ft_putstr_fd("pa\n", 1);
	if (a_or_b == 0)
		ft_putstr_fd("pb\n", 1);
}

void	sa_sb(t_stack **head, int a_or_b)
{
	if ((*head)->next != NULL)
	{
		int tmp;

		tmp = (*head)->content;
		(*head)->content = (*head)->next->content;
		(*head)->next->content = tmp;
		if (a_or_b == 1)
			ft_putstr_fd("sa\n", 1);
		if (a_or_b == 0)
			ft_putstr_fd("sb\n", 1);
	}
}
