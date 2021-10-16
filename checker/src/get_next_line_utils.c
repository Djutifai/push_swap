/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:29:05 by ftassada          #+#    #+#             */
/*   Updated: 2021/06/05 17:42:15 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		str[i++] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	i = 0;
	cc = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	lensum;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	lensum = len1 + len2;
	str = ft_calloc(sizeof(*str), (lensum + 1));
	if (!str)
		return (NULL);
	while (len1--)
		str[len1] = s1[len1];
	while (len2--)
		str[lensum-- -1] = s2[len2];
	if (s1)
		free((char *)s1);
	return (str);
}

char	*ft_strtrunc(char *str, char c)
{
	char	*res;
	ssize_t	i;
	ssize_t	j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = ft_calloc(sizeof(*res), ft_strlen(str) - i + 1);
	if (!res)
		return (NULL);
	while (str[++i])
		res[j++] = str[i];
	free(str);
	return (res);
}
