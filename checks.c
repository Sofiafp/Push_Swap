/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:14:21 by salegre-          #+#    #+#             */
/*   Updated: 2022/02/06 20:36:22 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	is_it_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-')
			return (0);
		if (arg[i + 1] != '\0')
			if (arg[i] == '-' && (arg[i + 1] < '0' || arg[i + 1] > '9'))
				return (0);
		if (arg[i] == '-' && arg[i + 1] == '\0')
			return (0);
		if (arg[i + 1] != '\0')
			if (arg[i + 1] == '-' && arg[i] > '0' && arg[i] < '9')
				return (0);
		i++;
	}
	return (1);
}

int	is_it_ordered(t_stack *head)
{
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

int	error_msg(t_stack **head)
{
	ft_putstr_fd("Try again <3\n", 2);
	clean_lst(&(*head));
	return (0);
}

int	does_it_repeat(t_stack *head)
{
	t_stack	*tmp;

	while (head->next != NULL)
	{
		tmp = head->next;
		while (tmp->next != NULL)
		{
			if (head->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		if (head->content == tmp->content)
			return (1);
		head = head->next;
	}
	return (0);
}