/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:27:18 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/27 18:28:18 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// muda os primeiros x caracteres por um caracter escolhido

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;

	str = (char *)b;
	i = 0;
	while (i != len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
/*
int main () 
{
   char str[] = "12345678901234567890";
   memset(str,'-',20);
   printf("Expected: %s\n", str);

   char str2[] = "12345678901234567890";
   ft_memset(str2,'-',20);
   printf("Output: %s\n", str2);
}*/
