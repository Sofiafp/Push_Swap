/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_on_purpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:06:26 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/15 19:37:22 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rrr_to_place(t_stack **head_a, t_stack **head_b, int i, int j, int a_or_b) 
{
	while(i-- > 0)
	{
		rrr(&(*head_a), &(*head_b));
	}
	while(j-- > 0)
	{
		if (a_or_b)
			rra_rrb(&(*head_a), a_or_b);
		else
			rra_rrb(&(*head_b), a_or_b);		
	}
}

void	rr_to_place(t_stack **head_a, t_stack **head_b, int i, int j, int a_or_b) 
{
	while(i-- > 0)
	{
		rr(&(*head_a), &(*head_b));
	}
	while(j-- > 0)
	{
		if (a_or_b)
			ra_rb(&(*head_a), a_or_b);
		else
			ra_rb(&(*head_b), a_or_b);
	}
}

void	rotate_it2(t_stack **head, int count, int a_or_b)
{
//	printf("count: %d\n", count);
	if (lst_size(*head) + 1 == count)
		return ;

	if (count > lst_size(*head) / 2)
	{
		count = lst_size(*head) - count + 1;
		while (count-- > 0)
			rra_rrb(&(*head), a_or_b);
	}
	else
	{
//		printf("oioi\n");
		while (count-- > 0)
			ra_rb(&(*head), a_or_b);
	}
}

void	do_less(t_stack **head_a, t_stack **head_b, int a, int b)
{
	int	len_a;
	int	len_b;
	
	len_a = lst_size(*head_a);
	len_b = lst_size(*head_b);
	if (a <= len_a/2 && b <= len_b/2)
	{
		if ( a <= b)
			rr_to_place(&(*head_a), &(*head_b), a, b - a, 0); //rr for a times and rb for b - a times
		else
			rr_to_place(&(*head_a), &(*head_b), b, a - b, 1);
	}
	else if (a > len_a/2 && b > len_b/2)
	{
		a = len_a - a + 1;
		b = len_b - b + 1;
		if ( a <= b )
			rrr_to_place(&(*head_a), &(*head_b), a, b - a, 0); //rrr for lena times and rb for b - a times
		else
			rrr_to_place(&(*head_b), &(*head_a), b, a - b, 1);//rrr for lena times and rb for b - a times	
	}
	else
	{
//		printf("a: %d\n", a);
//		printf("b: %d\n", b);
		rotate_it2(&(*head_a), a, 1);
		rotate_it2(&(*head_b), b, 0);		// rotate both
	}
}

int	position(t_stack *head_b, t_stack *node_to_put)
{
	int i;
	
	i = 0;
	if (node_to_put == get_tail(head_b))
		return (lst_size(head_b) + 1);
	while(head_b->next != NULL && head_b != node_to_put)
	{
		head_b = head_b->next;
		i++;
	}
	return (i + 1);
}

void and_do_it(t_stack **head_a, t_stack **head_b, t_stack *node_to_put)
{
	int a;
	int	b;

	a = find_the_place(*head_a, node_to_put->content) + 1;
	b = position(*head_b, node_to_put) - 1;
	// printf("a: %d\n", a);
	// printf("b: %d\n", b);
	if (a && b)
		do_less(&(*head_a), &(*head_b), a, b);
}
