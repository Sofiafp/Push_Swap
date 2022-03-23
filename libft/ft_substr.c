/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:54 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/31 17:00:51 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	max;
	char			*sbstr;
	int				i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	max = len + start;
	sbstr = (char *)malloc((len + 1) * sizeof(char));
	if (sbstr == NULL)
		return (0);
	i = 0;
	while (s[start] != '\0' && start < max)
	{
		sbstr[i] = s[start];
		i++;
		start++;
	}
	sbstr[i] = '\0';
	return (sbstr);
}
/*
int	main(void)
{
	char str[] = "hello";
	printf("%s", ft_substr("tripouille", 0, 42000));
}
*/
