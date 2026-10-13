/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:36:01 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/13 18:23:46 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putchar(nb % 10 + '0', count);
	}
	else
	{
		ft_putchar(nb + '0', count);
	}
}

void	ft_putunsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putunsigned(n / 10, count);
		ft_putchar(n % 10 + '0', count);
	}
	else
	{
		ft_putchar(n + '0', count);
	}
}

void	ft_puthex(unsigned long n, int uppercase, int *count)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16, uppercase, count);
	ft_putchar(base[n % 16], count);
}

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	n;

	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	n = (unsigned long)ptr;
	ft_putstr("0x", count);
	ft_puthex(n, 0, count);
}
