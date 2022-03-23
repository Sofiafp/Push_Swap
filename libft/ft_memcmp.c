/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:09:35 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/27 17:30:12 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int memcmp(const void *s1, const void *s2, size_t n)
// 0 se forem iguais
// 1 se s1 > s2
// -1 se s1 < s2
#include "libft.h"
#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (!n)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
    printf("Output: %d\n", ft_memcmp("He","Hello", 2));
    printf("Expected: %d\n", memcmp("He","Hello", 2));
}*/
