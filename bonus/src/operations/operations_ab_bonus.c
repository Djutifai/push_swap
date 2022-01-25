/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:43:34 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/15 20:51:39 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_env *env)
{
	sa(&env->a_head);
	sb(&env->b_head);
}

void	rr(t_env *env, long times)
{
	ra(&env->a_head, times);
	rb(&env->b_head, times);
}

void	rrr(t_env *env, long times)
{
	rra(&env->a_head, times);
	rrb(&env->b_head, times);
}
