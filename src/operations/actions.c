/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:29 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/09 16:36:07 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_elem **stack)
{
	long	temp;

	if ((*stack)->next == NULL)
		return ;
	temp = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = temp;
}

void	rotate(t_elem **stack, int is_reverse)
{
	if (is_reverse == FALSE)
		*stack = (*stack)->next;
	else
		*stack = (*stack)->prev;
}
