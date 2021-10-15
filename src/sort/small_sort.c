/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:21 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/12 22:56:17 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_rotate(t_env *env)
{
	int		i;
	long	a_head;

	a_head = env->a_head->val;
	i = 0;
	while (i++ < 5)
	{
		if (env->b_head != NULL)
		{
			if (env->a_head->val > env->b_head->val)
			{
				pa(env);
			}
			else if (i == 4 && env->b_size == 2)
				pa(env);
			else if (i == 5 && env->b_size == 1)
				pa(env);
		}
		ra(&env->a_head, 1);
	}
}

void	small_sort(t_env *env)
{
	if (env->a_size == 2)
		sort_two(&env->a_head, FALSE);
	else if (env->a_size == 3)
		sort_three_a(&env->a_head);
	else if (env->a_size > 3)
	{
		pb(env);
		if (env->a_size == 4)
		{
			pb(env);
			sort_two(&env->b_head, TRUE);
		}
		sort_three_a(&env->a_head);
		push_rotate(env);
	}
}
