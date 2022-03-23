/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_on_purpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:06:26 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/22 17:16:21 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rotate_it2(t_stack **head, int count, int a_or_b)
{
	if (lst_size(*head) + 1 == count)
		return ;
	if (count > lst_size(*head) / 2)
	{
		count = lst_size(*head) - count + 1;
		while (count-- > 0)
			rra_rrb(&(*head), a_or_b);
	}
	else
		while (count-- > 0)
			ra_rb(&(*head), a_or_b);
}

int	position(t_stack *head_b, t_stack *node_to_put)
{
	int	i;

	i = 0;
	if (node_to_put == get_tail(head_b))
		return (lst_size(head_b) + 1);
	while (head_b->next != NULL && head_b != node_to_put)
	{
		head_b = head_b->next;
		i++;
	}
	return (i + 1);
}

void	and_do_it(t_stack **head_a, t_stack **head_b, t_stack *node_to_put)
{
	int	a;
	int	b;

	a = find_the_place(*head_a, node_to_put->content) + 1;
	b = position(*head_b, node_to_put) - 1;
	if (a || b)
		do_less(&(*head_a), &(*head_b), a, b);
}
