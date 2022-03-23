/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:09:03 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/29 18:17:14 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// outputs null if doesnt find the char
// acepts when n is bigger than the legnth of the string

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	b;
	size_t			i;

	a = (unsigned char *)s;
	b = c;
	i = 0;
	if (!c && n == 0)
		return (NULL);
	while (i < n)
	{
		if (a[i] == b)
			return (a + i);
		i++;
	}
	if (c == '\0')
		return (a);
	return (0);
}
/*
int main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
    printf("%s\n", ft_memchr(s, 0, 0));
	char s2[] = {0, 1, 2 ,3 ,4 ,5};
    printf("%s\n", memchr(s2, 0, 0));
}*/

//NOTES
// ok então isto não me estava a funcionar só com const char *a & char b
// por isso coloquei unsigned char. 
// Ainda tive que dizer que a é igual a s* unsigned char
// return a + i é o pointer
