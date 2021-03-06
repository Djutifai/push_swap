/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:59:56 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/15 23:38:53 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_elem **elem)
{
	swap_two(elem);
}

void	pb(t_env *env)
{
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
		rotate(stack, FALSE);
}

void	rrb(t_elem **stack, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
		rotate(stack, TRUE);
}
