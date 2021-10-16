/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:15:55 by ftassada          #+#    #+#             */
/*   Updated: 2021/06/05 20:00:13 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	ft_free_null(char **strings)
{
	if (strings)
	{
		if (*strings)
		{
			free(*strings);
			*strings = NULL;
		}
	}
}

static int	ft_free_all(char **strs1, char **strs2, int flag)
{
	ft_free_null(strs1);
	ft_free_null(strs2);
	return (flag);
}

static char	*ft_get_line(char	*cache)
{
	ssize_t	i;
	char	*line;

	i = 0;
	if (!cache)
		return (NULL);
	while (cache[i] && cache[i] != '\n')
		i++;
	line = ft_calloc(sizeof(*cache), i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
	{
		line[i] = cache[i];
		i++;
	}
	return (line);
}

static int	ft_get_return(char **cache, char **line, char **buf, ssize_t fr)
{
	*line = ft_get_line(*cache);
	if (!(*line))
		return (ft_free_all(buf, cache, -1));
	*cache = ft_strtrunc(*cache, '\n');
	if (fr == 0)
		return (ft_free_all(buf, cache, 0));
	return (ft_free_all(buf, NULL, 1));
}

int	get_next_line(int fd, char **line)
{
	static char	*cache;
	char		*buf;
	ssize_t		fr;

	if (BUFFER_SIZE <= 0 || !line)
		return (-1);
	fr = 1;
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free_all(NULL, &cache, -1));
	while (fr && !ft_strchr(cache, '\n'))
	{
		fr = read(fd, buf, BUFFER_SIZE);
		if (fr == -1)
			return (ft_free_all(&buf, &cache, -1));
		buf[fr] = '\0';
		cache = ft_strjoin(cache, buf);
		if (!cache)
			return (ft_free_all(&buf, &cache, -1));
	}
	return (ft_get_return(&cache, line, &buf, fr));
}
