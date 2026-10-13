/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:56:02 by alexdos           #+#    #+#             */
/*   Updated: 2026/04/24 13:48:03 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("ft_isdigit =""%d\n", ft_isdigit('4'));
	printf("isdigit =""%d\n", isdigit('4'));	
	printf("ft_isdigit =""%d\n", ft_isdigit('p'));
	printf("isdigit =""%d\n", isdigit('p'));
}
*/