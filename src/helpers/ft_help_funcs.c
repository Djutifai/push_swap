/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:31 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/24 23:35:52 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_checker(int argc, char **argv)
{
	size_t	i;
	size_t	beginning;
	size_t	mover;

	i = 1;
	mover = 1;
	if (argc == 1)
		exit(0);
	while (argv[i])
		if (!ft_isdigit(argv[i++]))
			ft_put_error();
	while (mover < i)
	{
		beginning = 1;
		while (beginning < mover)
			if (ft_atoi(argv[beginning++]) == ft_atoi(argv[mover]))
				ft_put_error();
		mover++;
	}
}
