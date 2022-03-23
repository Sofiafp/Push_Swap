/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:07:46 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/25 19:04:01 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123)
		|| (c > 47 && c < 58))
		return (1);
	else
		return (0);
}
/*
int main()
{
    printf("Output: %d\n", ft_isalnum('9'));
    printf("Expected: %d\n", isalnum('9'));
}*/
