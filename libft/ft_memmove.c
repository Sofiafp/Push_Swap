/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:11:20 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/27 19:03:43 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cpoies len bytes from src to dst
// the copy is always done in a non-destructive manner ???
// returns the original value of dst ???

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*a;
	const char	*b;

	a = dst;
	b = src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (a < b)
	{
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			a[len] = b[len];
		}
	}
	return (dst);
}
/*
int main()
{
    char str1[] = "!!!!!!!";
    char str2[] = "Quizz";

    printf("%s\n",memmove(str1, str2, 2));

    char str3[] = "!!!!!!!";
    char str4[] = "Quizz";

    printf("%s\n",ft_memmove(str3, str4, 2));

}*/
