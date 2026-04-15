/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:28:57 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 15:30:18 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
	{
		return ;
	}
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
	{
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
	{
		return ;
	}
	write(fd, s, ft_strlen(s));
}
