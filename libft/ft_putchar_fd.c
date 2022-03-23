/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:12:17 by salegre-          #+#    #+#             */
/*   Updated: 2021/10/25 17:12:19 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//file description é aparentmente o primeiro parametro de write
//em vez de metermos 1, deixamos esse parametro aberto com 'fd'
#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main()
{
    ft_putchar_fd('!', 1);
}*/
