/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:18:50 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/29 19:16:53 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		n;
	char	paraefeitos;

	n = ft_strlen(str);
	paraefeitos = c;
	while (n + 1 != 0)
	{
		if (str[n] == paraefeitos)
			return ((char *)&str[n]);
		else
			n--;
	}
	return (0);
}
/*
int main()
{
    printf("Output: %s\n", ft_strrchr("abbbbbb", 'a'));
    printf("Expected: %s\n", strrchr("abbbbb", 'a'));
}*/
//era suposto ter a const mas isso ia dar problemas no return bleh
