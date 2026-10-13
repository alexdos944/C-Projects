/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:43:23 by alexdos           #+#    #+#             */
/*   Updated: 2026/04/27 14:42:53 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	i;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	i = 0;
	if (size <= lendst)
		return (size + lensrc);
	else
	{
		while (src[i] && lendst + i < size - 1)
		{
			dst[lendst + i] = src[i];
			i++;
		}
	}
	dst[lendst + i] = '\0';
	return (lensrc + lendst);
}
/*
int	main(void)
{
	char	dst[8] = "bon";
	size_t	len;

	len = ft_strlcat(dst, "jour", 8);
	printf("len = %zu\n", len);
	printf("dst = %s\n", dst);
	return (0);
}*/