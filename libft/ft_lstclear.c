/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:23:20 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/01 12:23:23 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		head = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = head;
	}
	*lst = NULL;
}
