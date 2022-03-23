/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:07:59 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/25 19:04:09 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cheack if a character is an alphabetical one
// returns 0 if False
// só aceita uma constante

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}
/*
int main()
{
    printf("Output: %d\n", ft_isalpha('['));
    printf("Expected: %d\n", isalpha('['));
}*/
