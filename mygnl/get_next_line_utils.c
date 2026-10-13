/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:00:32 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/31 16:36:38 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

char	*ft_extract(char *reste)
{
	char	*s;
	int		i;

	i = 0;
	if (!reste || !reste[0])
		return (NULL);
	while (reste[i] && reste[i] != '.')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (reste[i] && reste[i] != '.')
	{
		s[i] = reste[i];
		i++;
	}
	if (reste[i] == '.')
		s[i++] = '.';
	s[i] = '\0';
	return (s);
}

char	*ft_clean(char *reste)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!reste)
		return (NULL);
	while (reste[i] && reste[i] != '.')
		i++;
	if (!reste[i])
		return (ft_free(reste));
	i++;
	s = malloc(sizeof(char) * (ft_strlen(reste + i) + 1));
	while (reste[i])
	{
		s[j] = reste[i];
		i++;
		j++;
	}
	s[j] = '\0';
	free(reste);
	return (s);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free (s1);
	return (str);
}
