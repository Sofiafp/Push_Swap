/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:11 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/01 12:07:11 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locates the first occurence of a string
// if needle is an empty string, return the haystack
// if needle isnt in an haystack, return NULL
// otherwise, a pointer to the first char of the first
//   occurence of needle is returned
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	l_need;

	l_need = ft_strlen(needle);
	if (l_need == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] && (i + j) < n)
			j++;
		if (j == l_need)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
/*
int main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
    printf("Output: %s\n", ft_strnstr(haystack, "", 8));
	char haystack1[30] = "aaabcabcd";
	char needle1[10] = "aabc";
    printf("Expected: %s\n", strnstr(haystack, "cd", 8));
}*/

//NOTES
// return haystack[i - l] porque quero imprimir desde o 
//   início do needle no haystack
//  por isso retiro o length do needle à posição de i

//não pus const prq deixa the funcionar SÓ a parte do return

//esta merda funciona na merda do python tutor mas NÃO FUNCIONA AQUI !
