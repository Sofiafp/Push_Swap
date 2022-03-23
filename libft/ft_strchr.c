/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:22 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/29 19:13:38 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//locates the first occurence of c
//returns the rest of the word from the located letter OR null
//the terminating null char is considered a part of the string,
// therefore the function located the terminating '\0'

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	paraefeitos;

	i = 0;
	paraefeitos = c;
	while (str[i] != '\0')
	{
		if (str[i] == paraefeitos)
			return ((char *)str + i);
		else
			i++;
	}
	if (str[i] == paraefeitos)
		return ((char *)str + i);
	return (0);
}
/*
int main()
{
    printf("Output: %s\n", ft_strchr("tripouille", 't' + 256));
    printf("Expected: %s\n", strchr("tripouille", 't' + 256));
	printf("%c",'t' + 256);

}*/

//EXPLICAÇÃO
// a segunda variável aceite por ft_strchr é um int
//  porque a função original é assim

// n é o length do string

// o While serve para ver se o character existe no string

// 1º if
// Se o c for o null-terminated character,
// o Check é o segunte
// Se o while iterar por todo o string & c for '\0'
//  então este if vai ser verdade e vamos returnar o
//  null terminated string.

// 2º if
// Se o while iterar completamente e não encontrar c no string
// retorna NULL

// 3º if
// se nenhum dos outros for verdade então imprime o resto do string

//O Return não podem ser só return(str), tens que mudar para char *
