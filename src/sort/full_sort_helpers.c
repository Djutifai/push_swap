/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:30:03 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/12 23:14:31 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mmm	init_mmm(t_env *env)
{
	t_mmm	mmm;

	mmm.min = env->array[0];
	mmm.mid = env->array[(env->a_size - 1) / 2];
	mmm.max = env->array[env->a_size - 1];
	return (mmm);
}

void	init_stack_b(t_env *env, long min, long mid, long max)
{
	int	count;

	count = 0;
	while (count != 3)
	{
		if (env->a_head->val != min && env->a_head->val != max)
		{
			pb(env);
			if (env->b_head->val > mid && env->b_size > 1)
				rb(&env->b_head, 1);
		}
		else
		{
			ra(&env->a_head, 1);
			++count;
		}
	}
}
