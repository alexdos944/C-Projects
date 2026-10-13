/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:07:11 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/01 15:03:22 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_getword(char const *s, char c, int start)
{
	size_t	i;
	char	*word;
	size_t	len;

	i = start;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	len = i - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	return (word);
}

static void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	fill(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			tab[j] = ft_getword(s, c, i);
			if (!tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (wcount(s, c) + 1));
	if (!tab)
		return (NULL);
	tab[wcount(s, c)] = NULL;
	if (!fill(tab, s, c))
	{
		ft_free(tab);
		return (NULL);
	}
	return (tab);
}
/*
int	main(void)
{
	char	**tab;
	int	i;

	i = 0;
	tab = ft_split("BONJOUR J/E M'APP/ELLE OBV/IOUS", '/');

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	ft_free(tab);
	return(0);
}*/