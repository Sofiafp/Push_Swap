/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:05:14 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/01 12:05:15 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//saltar espaços
// só aceita um sinal
// qndo não dá imprime um 0
// não esquecer bigger numbers

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_sinal(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	long int	i;
	int			sinal;
	long int	n;

	n = 0;
	sinal = 1;
	i = ft_isspace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		sinal = ft_sinal(str, i);
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		n = n + str[i] - 48;
		n = n * 10;
		i++;
	}
	n /= 10;
	return (sinal * n);
}
/*
int main()
{
    char str[] = "  -5432123";
    printf("Output: %d\n", ft_atoi(str));
    printf("Expected: %d\n", atoi(str));
}*/
