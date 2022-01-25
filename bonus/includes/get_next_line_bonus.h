/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 01:12:30 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/25 21:33:00 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrunc(char *str, char c);
char	*ft_strchr(const char *s, int c);

#endif
