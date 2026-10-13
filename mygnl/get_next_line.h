/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:38:14 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/24 18:26:34 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1000

# endif

char	*get_next_line(int fd);
int		ft_strchr_gnl(char *s, char c);
char	*ft_extract(char *reste);
char	*ft_clean(char *reste);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_free_return(char *buf, char *line);
char	*ft_free(char *s);
char	*ft_free_stash(char **stash);

#endif