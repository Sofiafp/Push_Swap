/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:07:26 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/01 12:07:28 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	nalg(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (isneg(n))
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l;
	int		i;

	i = 0;
	l = nalg(n) + isneg(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (isneg(n))
	{
		n *= -1;
		str[i] = '-';
	}
	str[l] = '\0';
	while (l-- != 0 && n != 0)
	{
		str[l] = (n % 10) + 48;
		n = n / (10);
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
    printf("%s\n", ft_itoa(-5656));
}
*/
