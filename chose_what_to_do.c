/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_what_to_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:41:41 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/09 16:34:06 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	chose_aux(t_stack *head_a, t_stack *places)
{
	int len_a;
	int	len_p;
	int i;
	
	len_a = lst_size(head_a);
	len_p = lst_size(places);
	i = 0;
//	while(i <= len_p/2)
//	{
//		if (len_a > len_p)		
//	}
	return (i);
}

int chose_what_to_do(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tail;
	t_stack	*places;
	int j;
	
	tail = get_tail(head_b);
	places = NULL;
	j = 0;
	while (tail->prev != NULL)
	{
		printlist(head_a, 1);
		printlist(head_b, 1);
		printf("\n");
		j = find_the_place(head_a, tail->content);
		insert_at_head(&places, create_new_node(j + 1));
		tail = tail->prev;
	}
	j = find_the_place(head_a, tail->content);
	insert_at_head(&places, create_new_node(j + 1));
	int i;
	i = 2;
	printf("places->content: %d\n", places->content);
	printf("lst_size: %d\n", lst_size(places));
//	i = chose_aux(head_a, head_b);
	printlist(places, 0);
	return (1);
}
