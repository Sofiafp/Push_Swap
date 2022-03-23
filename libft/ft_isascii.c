/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:08:21 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/25 19:07:45 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main()
{
    printf("Output: %d\n", ft_isascii(1));
    printf("Expected: %d\n", isascii(1));
}*/
