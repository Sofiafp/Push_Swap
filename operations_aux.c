/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:26:00 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/22 17:26:38 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	sa_sb(t_stack **head, int a_or_b)
{
	int	tmp;

	if ((*head)->next != NULL)
	{
		tmp = (*head)->content;
		(*head)->content = (*head)->next->content;
		(*head)->next->content = tmp;
		if (a_or_b == 1)
			ft_putstr_fd("sa\n", 1);
		if (a_or_b == 0)
			ft_putstr_fd("sb\n", 1);
	}
}
