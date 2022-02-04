/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:29 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/29 14:25:49 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_two(t_elem **stack)
{
	long	temp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = temp;
}

void	rotate(t_elem **stack, int is_reverse)
{

	if (!*stack || (*stack)->next == NULL)
		return ;
	if (is_reverse == FALSE)
		*stack = (*stack)->next;
	else
		*stack = (*stack)->prev;
}

void	get_score(t_env *env)
{
	t_elem	*a_move;
	t_elem	*b_move;
	long	i;
	long	j;
	long	score;

	i = 0;
	j = 0;
	while (j < env->b_size)
	{
		a_move = env->a_head;
		b_move = env->b_head;
		score = 0;
	}
}
