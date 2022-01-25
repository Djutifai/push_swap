/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saf_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 03:35:03 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/25 21:08:49 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	atoi_on_steroids(char *str, int l, int r)
{
	long	i;
	int		minus;
	int		digits;

	digits = 0;
	i = 0;
	minus = 1;
	if (str[l] == '+')
		l++;
	else if (str[l] == '-')
	{
		minus = -1;
		l++;
	}
	while (str[l] && l < r && str[l] >= '0' && str[l] <= '9')
	{
		i = i * 10 + (str[l] - '0');
		if (++digits > MAX_INT_DIGITS)
			ft_put_error();
		l++;
	}
	if (!(i * minus >= INT_MIN && i * minus <= INT_MAX))
		ft_put_error();
	return (i * minus);
}

long	*nums_builder(char *str, int amount_of_nums)
{
	long		*nums;
	int			i;
	int			l;
	int			r;

	i = 0;
	r = 0;
	nums = malloc(sizeof(*nums) * amount_of_nums);
	while (i < amount_of_nums && str[r])
	{
		if (str[r] == '-' || str[r] == '+' || (str[r] >= '0' && str[r] <= '9'))
		{
			l = r;
			while (str[r] && str[r] != ' ')
				r++;
			nums[i++] = atoi_on_steroids(str, l, r);
		}
		r++;
	}
	return (nums);
}
