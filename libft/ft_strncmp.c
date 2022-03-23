/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:16:58 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/29 19:19:59 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compares not more than n characters
#include <string.h>
#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main()
{
    printf("Output: %d\n", ft_strncmp("t", "", 0));
    printf("Expected: %d\n", strncmp("t", "", 0));
}
*/
//NOTES
// o primeiro if 
// por alguma razão o original, quando n= 0 e algum dos strings é vazio
//  imprime 0, este if works to acomplish that.
