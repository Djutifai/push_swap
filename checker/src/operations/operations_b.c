/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:59:56 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/16 17:40:31 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_elem **elem)
{
	ft_putstr("sb\n");
	swap_two(elem);
}

void	pb(t_env *env)
{
	ft_putstr("pb\n");
	if (env->a_head == NULL)
		return ;
	if (env->b_size > 1)
		push_to_b(env);
	else
		push_to_small_b(env);
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
