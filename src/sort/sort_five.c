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

void	sort_five(t_env *env)
{
	if (env->a_size == 2)
		sort_two(&env->a_head);
	else if (env->a_size == 3)
		sort_three(&env->a_head);
	else if (env->a_size == 4)
	{
		//pa();
	}
}
