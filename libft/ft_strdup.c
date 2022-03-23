/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:36 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/01 12:06:20 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//saves a copy of a string
//must allocate memory for the copy
//returns a pointer
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		n;
	int		i;

	n = ft_strlen(str);
	cpy = (char *)malloc((n + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*
int main()
{
    printf("Output: %s\n", ft_strdup(""));
    printf("Expected: %s\n", strdup(""));   
}*/

//NOTES
// não sei se devo definir n como size_t ou int
// funciona das duas maneiras não sei se fode.
