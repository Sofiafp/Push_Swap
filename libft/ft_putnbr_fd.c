/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:10:44 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/01 14:11:47 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nchar(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	power(int count)
{
	int	a;

	a = 1;
	while (count > 0)
	{
		a *= 10;
		count--;
	}
	return (a);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		count;
	int		a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = n * (-1);
		write(fd, "-", 1);
	}
	count = nchar(n) - 1;
	while (count > 0)
	{
		a = n / (power(count));
		ft_putnbr_fd(a, fd);
		n = n - a * (power(count));
		count--;
	}
	ft_putchar_fd((n % 10) + 48, fd);
}
