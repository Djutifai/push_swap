/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:21 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/09 10:44:37 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_rotate(t_env *env)
{
	int i;

	i = 0;
	while (i++ < 5)
	{
		if (env->a_head->val > env->b_head->val)
			pa(env);
		ra(&env->a_head, 1);
	}
}

void	sort_five(t_env *env)
{
	if (env->a_size == 2)
		sort_two(&env->a_head);
	else if (env->a_size == 3)
		sort_three(&env->a_head);
	else if (env->a_size > 3)
	{
		pb(env);
		printf("qwe\n");
		if (env->a_size == 5)
		{
			pb(env);
			sort_two(&env->b_head);
		}
		sort_three(&env->a_head);
		push_rotate(env);
	}
}
