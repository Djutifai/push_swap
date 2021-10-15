/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:17 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/10 23:26:19 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_elem **stack)
{
	if ((*stack)->val > (*stack)->next->val && (*stack)->next->val \
		> (*stack)->prev->val)
	{
		sa(stack);
		rra(stack, 1);
	}
	else if ((*stack)->val > (*stack)->next->val && (*stack)->next->val \
		< (*stack)->prev->val)
	{
		if ((*stack)->val > (*stack)->prev->val)
			ra(stack, 1);
		else
			sa(stack);
	}
	else if ((*stack)->val < (*stack)->next->val && (*stack)->next->val \
		> (*stack)->prev->val)
	{
		rra(stack, 1);
		if ((*stack)->val > (*stack)->next->val)
			sa(stack);
	}
}

void	sort_three_b(t_elem **stack)
{
	if ((*stack)->val > (*stack)->next->val && (*stack)->next->val \
		> (*stack)->prev->val)
	{
		sb(stack);
		rrb(stack, 1);
	}
	else if ((*stack)->val > (*stack)->next->val && (*stack)->next->val \
		< (*stack)->prev->val)
	{
		if ((*stack)->val > (*stack)->prev->val)
			rb(stack, 1);
		else
			sb(stack);
	}
	else if ((*stack)->val < (*stack)->next->val && (*stack)->next->val \
		> (*stack)->prev->val)
	{
		rrb(stack, 1);
		if ((*stack)->val > (*stack)->next->val)
			sb(stack);
	}
}

void	sort_two(t_elem **stack, int is_b)
{
	if (is_b == FALSE)
	{
		if ((*stack)->val > (*stack)->next->val)
			sa(stack);
	}
	else
	{
		if ((*stack)->val > (*stack)->next->val)
			sb(stack);
	}
}
