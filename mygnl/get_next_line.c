/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:10:27 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/31 16:37:56 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_free_return(char *buf, char *line)
{
	free (buf);
	return (line);
}

char	*ft_free_stash(char **stash)
{
	free(*stash);
	*stash = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			ret;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr_gnl(stash, '.') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret >= 0)
			buf[ret] = '\0';
		if (ret > 0)
			stash = ft_strjoin(stash, buf);
	}
	if (ret < 0)
		return (ft_free_return(buf, ft_free_stash(&stash)));
	line = ft_extract(stash);
	stash = ft_clean(stash);
	return (ft_free_return(buf, line));
}

#include <fcntl.h>

int main(void)
{
    char    *line;
    int     fd;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
