/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:59:56 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/09 11:13:44 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_elem **elem)
{
	ft_putstr("sa\n");
	swap_two(elem);
}

void	pb(t_env *env)
{
	ft_putstr("pb\n");
	push_to_b(env);
}

void	rb(t_elem **stack, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
	{
		ft_putstr("rb\n");
		rotate(stack, FALSE);
	}
}

void	rrb(t_elem **stack, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
	{
		ft_putstr("rrb\n");
		rotate(stack, TRUE);
	}
}
