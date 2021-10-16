/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:43:34 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/16 17:40:31 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_env *env)
{
	ft_putstr("ss\n");
	sa(&env->a_head);
	sb(&env->b_head);
}

void	rr(t_env *env, long times)
{
	ft_putstr("rr\n");
	ra(&env->a_head, times);
	rb(&env->b_head, times);
}

void	rrr(t_env *env, long times)
{
	ft_putstr("rrr\n");
	rra(&env->a_head, times);
	rrb(&env->b_head, times);
}
