/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:09:52 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/27 17:56:52 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*a;
	const char	*b;
	size_t		i;

	a = dst;
	b = src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>

int main()
{

    char dst1[20] = "";
    char src1[] = "";

    printf("Output: %s\n", ft_memcpy(dst1,src1,4));

	char dst[20] = "";
    char src[] = "";

    printf("Expected: %s\n", memcpy(dst,src,4));
}*/
