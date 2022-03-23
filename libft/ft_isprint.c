/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:11:00 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/25 19:03:40 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns 0 if a caracter is not printable
// 1 if it is printable
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main()
{
    printf("Output: %d\n", ft_isprint(128));
    printf("Expected: %d\n", isprint(128));
}*/
