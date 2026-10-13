/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:16:56 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/05 03:26:15 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	st = 0;
	end = ft_strlen(s1);
	while (st < end && ft_strchr(set, s1[st]))
		st++;
	while (end > st && ft_strchr(set, s1[end - 1]))
		end--;
	str = malloc(sizeof(char) * (end - st + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < end - st)
	{
		str[i] = s1[st + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main (void)
{
	printf("%s\n", ft_strtrim("+-/alexis/+-/", "-+"));
	return (0);
}*/