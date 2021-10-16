/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:27 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/16 17:40:31 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_elem **elem)
{
	ft_putstr("sa\n");
	swap_two(elem);
}

void	pa(t_env *env)
{
	ft_putstr("pa\n");
	if (env->b_head == NULL)
		return ;
	if (env->a_size > 1)
		push_to_a(env);
	else
		push_to_small_a(env);
}

void	ra(t_elem **stack, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
	{
		ft_putstr("ra\n");
		rotate(stack, FALSE);
	}
}

void	rra(t_elem **stack, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
	{
		ft_putstr("rra\n");
		rotate(stack, TRUE);
	}
}
