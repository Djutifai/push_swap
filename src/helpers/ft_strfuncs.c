/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:04:52 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/15 22:11:07 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\n' \
			|| c == '\r')
		return (1);
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_put_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int	ft_isdigit(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str && !(*str >= '0' && *str <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	long	i;
	int		minus;
	int		digits;

	digits = 0;
	i = 0;
	minus = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str++ - '0');
		digits++;
		if (digits > MAX_INT_DIGITS)
			ft_put_error();
	}
	if (!(i * minus >= INT_MIN && i * minus <= INT_MAX))
		ft_put_error();
	return (i * minus);
}
