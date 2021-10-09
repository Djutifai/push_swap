/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:17 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/09 16:12:00 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_elem **stack)
{
	if ((*stack)->val > (*stack)->next->val && (*stack)->next->val > (*stack)->prev->val) // 3 2 1
	{
		sa(stack);
		rra(stack, 1);
	}// 2 1 3 && 3 1 2
	else if ((*stack)->val > (*stack)->next->val && (*stack)->next->val \
		< (*stack)->prev->val)
	{
		if ((*stack)->val > (*stack)->prev->val)
			ra(stack, 1);
		else
			sa(stack);
	}// 1 3 2 && 2 3 1
	else if ((*stack)->val < (*stack)->next->val && (*stack)->next->val \
		> (*stack)->prev->val)
	{
		rra(stack, 1);
		if ((*stack)->val > (*stack)->next->val)
			sa(stack);
	}
}

void	sort_two(t_elem **stack)
{
	if ((*stack)->val > (*stack)->next->val)
		sa(stack);
}
