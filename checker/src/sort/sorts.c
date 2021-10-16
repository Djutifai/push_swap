/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:22:37 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/16 17:40:31 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	last_sort(t_env *env, t_elem *head)
{
	long	rotates;
	t_elem	*move;

	rotates = 0;
	move = env->a_head;
	while (move != head)
	{
		move = move->next;
		rotates++;
	}
	if (rotates < env->a_size - rotates)
		ra(&env->a_head, rotates);
	else
		rra(&env->a_head, env->a_size - rotates);
}

void	sort_this(t_env *env)
{
	if (env->a_size <= 5)
		small_sort(env);
	else
		full_sort(env);
}

static void	swap(long *a, long *b)
{
	long	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static long	partition(long *array, long low, long high, long *swaps)
{
	long	pivot;
	long	i;
	long	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			*swaps += 1;
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	sort_array(t_env *env, long low, long high, long *swaps)
{
	long	pi;

	if (low < high)
	{
		pi = partition(env->array, low, high, swaps);
		sort_array(env, low, pi - 1, swaps);
		sort_array(env, pi + 1, high, swaps);
	}
}
