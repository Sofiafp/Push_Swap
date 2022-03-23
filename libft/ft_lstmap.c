/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:25:11 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/01 12:25:26 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*scd_lst;
	t_list	*new;

	if (!lst)
		return (NULL);
	scd_lst = 0;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&scd_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&scd_lst, new);
		lst = lst->next;
	}
	return (scd_lst);
}
