/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:45:23 by alexdos           #+#    #+#             */
/*   Updated: 2026/04/27 15:07:43 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int srchar)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)srchar)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)srchar)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	*p;

	p = ft_strchr("bonjour", 'j');
	printf("%s\n", p);
}*/