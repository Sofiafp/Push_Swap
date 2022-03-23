/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:15:48 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/25 17:15:50 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	j;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	j = dstsize;
	while (*dst)
	{
		dst++;
		if (j > 0)
			j--;
	}
	while (*src && j > 1)
	{
		*dst++ = *src++;
		j--;
	}
	*dst = '\0';
	if (dstsize > dst_l)
		return (dst_l + src_l);
	return (dstsize + src_l);
}
/*
int main()
{
    char s11[20] = "Hellllllo";
    char s21[20] = "HOOOOOOOOOO";
    printf("Output: %d\n", ft_strlcat(s11, s21, 0));
    char s1[20] = "Hellllllo";
    char s2[20] = "HOOOOOOOOOO";
    printf("Expected: %lu\n", strlcat(s1, s2, 0));
}*/
