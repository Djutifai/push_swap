/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:37:23 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/13 22:53:51 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_env *env)
{
	t_elem	*temp;

	if (env->b_head == NULL)
		return ;
	temp = env->b_head;
	env->b_head = temp->next;
	temp->next = env->a_head;
	env->a_head->prev->next = temp;
	if (env->b_head != NULL)
		env->b_head->prev = temp->prev;
	temp->prev = env->a_head->prev;
	env->a_head->prev = temp;
	env->a_head = temp;
	if (env->b_size == 2)
	{
		env->b_head->prev = NULL;
		env->b_head->next = NULL;
	}
	else if (env->b_size > 2)
	{
		env->b_head->prev->next = env->b_head;
		env->b_head->next->prev = env->b_head;
	}
	env->a_size++;
	env->b_size--;
}

void	push_to_small_a(t_env *env)
{
	t_elem	*elem;

	elem = env->b_head;
	env->b_head = elem->next;
	if (env->b_size > 1)
	{
		elem->next->prev = elem->prev;
		elem->prev->next = elem->next;
	}
	env->b_size--;
	if (env->a_size == 0)
	{
		env->a_head = elem;
		elem->prev = NULL;
		elem->next = NULL;
		env->a_size++;
		return ;
	}
	env->a_head->prev = elem;
	env->a_head->next = elem;
	elem->next = env->a_head;
	elem->prev = env->a_head;
	env->a_head = elem;
	env->a_size++;
}

void	push_to_b(t_env *env)
{
	t_elem	*temp;

	temp = env->a_head;
	env->a_head = temp->next;
	temp->next = env->b_head;
	env->b_head->prev->next = temp;
	if (env->a_head != NULL)
		env->a_head->prev = temp->prev;
	temp->prev = env->b_head->prev;
	env->b_head->prev = temp;
	env->b_head = temp;
	if (env->a_size == 2)
	{
		env->a_head->prev = NULL;
		env->a_head->next = NULL;
	}
	else if (env->a_size > 2)
		env->a_head->prev->next = env->a_head;
	env->a_size--;
	env->b_size++;
}

void	push_to_small_b(t_env *env)
{
	t_elem	*elem;

	elem = env->a_head;
	env->a_head = elem->next;
	if (env->a_size > 1)
	{
		elem->next->prev = elem->prev;
		elem->prev->next = elem->next;
	}
	env->a_size--;
	if (env->b_size == 0)
	{
		env->b_head = elem;
		elem->prev = NULL;
		elem->next = NULL;
		env->b_size++;
		return ;
	}
	env->b_head->prev = elem;
	env->b_head->next = elem;
	elem->next = env->b_head;
	elem->prev = env->b_head;
	env->b_head = elem;
	env->b_size++;
}
