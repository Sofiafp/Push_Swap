/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_place_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:14:39 by salegre-          #+#    #+#             */
/*   Updated: 2022/02/15 16:33:01 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	*create_dif_lst(int *lst, t_stack *head, int val)
{
	int	i;
	int	len;

	i = 0;
	len = lst_size(head) + 1;
	while (i <= len && head->next != NULL)
	{
		lst[i] = head->content - val;
		i++;
		head = head->next;
	}
	lst[i] = head->content - val;
	return (lst);
}

int	*create_abs_lst(int *lst_abs, int *lst, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (lst[i] < 0)
			lst_abs[i] = lst[i] * -1;
		else
			lst_abs[i] = lst[i];
		i++;
	}
	return (lst_abs);
}

int	find_the_smalest(int *lst, int len)
{
	int	i;
	int	smallest;

	i = 1;
	smallest = 0;
	while (i <= len)
	{
		if (lst[smallest] > lst[i])
			smallest = i;
		i++;
	}
	if (smallest == 0)
		smallest--;
	return (smallest);
}

t_stack	*rotate_it(t_stack *head, int count)
{
	if (lst_size(head) == count)
		return (head);
	count++;
	if (count > lst_size(head) / 2)
	{
		count = lst_size(head) - count + 1;
		while (count--)
			rra_rrb(&(head), 1);
	}
	else
	{
		while (count--)
			ra_rb(&(head), 1);
	}
	return (head);
}

int	find_the_place(t_stack **head, int val)
{
	int	*lst;
	int	*lst_abs;
	int	index;

	if ((*head)->content > val && get_tail(*head)->content < val)
		return (lst_size(*head));
	lst = (int *)malloc((lst_size(*head) + 1) * sizeof(int));
	lst = create_dif_lst(lst, *head, val);
	lst_abs = (int *)malloc((lst_size(*head) + 1) * sizeof(int));
	lst_abs = create_abs_lst(lst_abs, lst, lst_size(*head));
	int i = 0;
	while (lst[i])
	{
		printf("lst_abs[%d] = %d\t\tlst_abs[%d] = %d\n", i, lst[i], i, lst_abs[i]);
		i++;
	}
	index = find_the_smalest(lst_abs, lst_size(*head));
	if (index != 0)
	{
		if (lst[index] > 0 && lst[index - 1] < 0)
			index--;
		if (lst[index] < 0 && lst[index - 1] > 0)
			index--;
	}
	printf("index: %d\n",index);
	free(lst);
	free(lst_abs);
	return (index);
}
