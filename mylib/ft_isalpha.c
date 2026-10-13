/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:54:45 by alexdos           #+#    #+#             */
/*   Updated: 2026/04/26 18:53:32 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c <= 122))
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("ft_isalpha =""%d\n", ft_isalpha(42));
	printf("isalpha =""%d\n", isalpha(42));	
	printf("ft_isalpha =""%d\n", ft_isalpha('p'));
	printf("isalpha =""%d\n", isalpha('p'));
}*/