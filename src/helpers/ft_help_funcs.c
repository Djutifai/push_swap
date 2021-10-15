/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:31 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/15 23:03:51 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	ft_putstr("\n");
	exit(0);
}

void	args_checker(int argc, char **argv)
{
	size_t	i;

	i = 1;
	if (argc == 1)
		ft_exit();
	while (argv[i])
		if (!ft_isdigit(argv[i++]))
			ft_put_error();
}
