/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:06:03 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/25 17:06:07 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns nothing(????) because it is void (???)
// ok supostamente diz que escreve o string, 
//  mas a função original não escreve nada, 
// por isso eu não pus nenhum write
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	i = 0;
	c = s;
	if (n == 0)
		return ;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
/*
#include <string.h>
int main()
{
    char str[15];
    ft_bzero(str,15);
    printf("\n");
    char str2[15];
    bzero(str2,15);
}*/
