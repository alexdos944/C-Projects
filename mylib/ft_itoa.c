/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:39:39 by alexdos           #+#    #+#             */
/*   Updated: 2026/04/29 19:52:42 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + sign);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		end;
	long	nb;

	nb = n;
	len = numlen(nb);
	end = len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nb = -nb;
	}
	while (len != 0)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	str[end] = '\0';
	return (str);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
}*/