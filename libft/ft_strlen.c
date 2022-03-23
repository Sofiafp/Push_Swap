/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:16:21 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/25 17:16:22 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the function returns
#include "libft.h"
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int main()
{
    printf("Output: %lu\n", ft_strlen("hello"));
    printf("Expected: %lu\n", strlen("hello"));
}*/

//NOTES
// Mudei int para unsigned long tanto na função como na definição de i
// porque strlen original usa %lu
// não sei se funciona

//SOLVE
// Descobri que strlen usa size_t, troquei unsigned long para size_t
