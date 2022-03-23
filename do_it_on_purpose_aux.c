/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_on_purpose_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:15:43 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/22 17:24:53 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rrr_b_to_place(t_stack **head_a, t_stack **head_b, int i, int j)
{
	while (i-- > 0)
		rrr(&(*head_a), &(*head_b));
	while (j-- > 0)
		rra_rrb(&(*head_b), 0);
}

void	rrr_a_to_place(t_stack **head_a, t_stack **head_b, int i, int j)
{
	while (i-- > 0)
		rrr(&(*head_a), &(*head_b));
	while (j-- > 0)
		rra_rrb(&(*head_a), 1);
}

void	rr_a_to_place(t_stack **head_a, t_stack **head_b, int i, int j)
{
	while (i-- > 0)
		rr(&(*head_a), &(*head_b));
	while (j-- > 0)
		ra_rb(&(*head_a), 1);
}

void	rr_b_to_place(t_stack **head_a, t_stack **head_b, int i, int j)
{
	while (i-- > 0)
		rr(&(*head_a), &(*head_b));
	while (j-- > 0)
		ra_rb(&(*head_b), 0);
}

void	do_less(t_stack **head_a, t_stack **head_b, int a, int b)
{
	if (a <= lst_size(*head_a) / 2 && b <= lst_size(*head_b) / 2)
	{
		if (a <= b)
			rr_b_to_place(&(*head_a), &(*head_b), a, b - a);
		else
			rr_a_to_place(&(*head_a), &(*head_b), b, a - b);
	}
	else if (a > lst_size(*head_a) / 2 && b > lst_size(*head_b) / 2)
	{
		a = lst_size(*head_a) - a + 1;
		b = lst_size(*head_b) - b + 1;
		if (a <= b)
			rrr_b_to_place(&(*head_a), &(*head_b), a, b - a);
		else
			rrr_a_to_place(&(*head_a), &(*head_b), b, a - b);
	}
	else
	{
		rotate_it2(&(*head_a), a, 1);
		rotate_it2(&(*head_b), b, 0);
	}
}
