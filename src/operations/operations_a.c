/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:27 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/09 16:15:07 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_elem **elem)
{
	ft_putstr("sa\n");
	swap_two(elem);
}

void	pa(t_env *env)
{
	ft_putstr("pa\n");
	push_to_a(env);
}

void	ra(t_elem **stack, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
	{
		ft_putstr("ra\n");
		rotate(stack, FALSE);
		printf("%ld nu\n", (*stack)->val);
	}
}

void	rra(t_elem **stack, int times)
{
	int	i;

	i = 0;
	while (i++ < times)
	{
		ft_putstr("rra\n");
		rotate(stack, TRUE);
	}
}
