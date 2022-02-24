/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_three_algs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:25:22 by salegre-          #+#    #+#             */
/*   Updated: 2022/02/06 19:52:44 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_stack	*two_algs(t_stack *head)
{
	if (head->content > head->next->content)
		sa_sb(&head, 1);
	return (head);
}

void	three_als_aux(int i, int j, int k, t_stack **head_a)
{
	t_stack	*tail_a;

	tail_a = get_tail(*head_a);
	if (i < j)
	{	
		if (j > k && k > i)
		{
			rra_rrb(&(*head_a), 1);
			sa_sb(&(*head_a), 1);
		}
		else if (j > k && k < i)
			rra_rrb(&(*head_a), 1);
	}
	else if (j > k)
	{
		ra_rb(&(*head_a), 1);
		sa_sb(&(*head_a), 1);
	}
	else if (k < i)
	{
		ra_rb(&(*head_a), 1);
	}
	else
		sa_sb(&(*head_a), 1);
}

t_stack	*three_als(t_stack *head)
{
	int	i;
	int	j;
	int	k;

	i = head->content;
	j = head->next->content;
	k = head->next->next->content;
	three_als_aux(i, j, k, &head);
	return (head);
}
