/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:17:42 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/01 12:12:58 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		fin;
	int		intro;

	if (!s1 || !set)
		return (NULL);
	intro = 0;
	while (s1[intro] && ft_strchr(set, s1[intro]))
		intro++;
	fin = ft_strlen(s1) - 1;
	while (fin && ft_strchr(set, s1[fin]))
		fin--;
	return (ft_substr(s1, intro, fin - intro + 1));
}
