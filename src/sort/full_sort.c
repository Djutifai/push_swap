/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:42:37 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/15 19:55:42 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_head(t_env *env, long value)
{
	long	lscore;
	long	rscore;
	t_elem	*temp_elem;

	lscore = 0;
	rscore = 0;
	temp_elem = env->a_head;
	while (!(temp_elem->prev->val < value && value < temp_elem->val))
	{
		temp_elem = temp_elem->next;
		++lscore;
	}
	temp_elem = env->a_head;
	while (!(temp_elem->prev->val < value && value < temp_elem->val))
	{
		temp_elem = temp_elem->prev;
		++rscore;
	}
	if (lscore > rscore)
		rra(&env->a_head, rscore);
	else
		ra(&env->a_head, lscore);
}

static void	rotate_elem_to_b_head(t_env *env, t_elem *elem_b)
{
	long	lscore;
	long	rscore;
	t_elem	*temp_elem;

	lscore = 0;
	rscore = 0;
	temp_elem = elem_b;
	while (temp_elem != env->b_head)
	{
		temp_elem = temp_elem->next;
		++lscore;
	}
	temp_elem = elem_b;
	while (temp_elem != env->b_head)
	{
		temp_elem = temp_elem->prev;
		++rscore;
	}
	if (lscore > rscore)
		rb(&env->b_head, rscore);
	else
		rrb(&env->b_head, lscore);
}

static void	sort_by_score(t_env *env)
{
	t_elem	*move_b;
	t_elem	*min_elem_b;
	long	min_score;

	if (env->b_size > 1)
		move_b = env->b_head->next;
	else
		move_b = env->b_head;
	min_score = move_b->elem_score;
	min_elem_b = move_b;
	while (move_b != NULL && move_b != env->b_head)
	{
		move_b = move_b->next;
		if (move_b->elem_score < min_score)
		{
			min_score = move_b->elem_score;
			min_elem_b = move_b;
		}
	}
	rotate_a_head(env, min_elem_b->val);
	rotate_elem_to_b_head(env, min_elem_b);
	pa(env);
}

void	full_sort(t_env *env)
{
	t_mmm	mmm;
	t_elem	*a_head;

	mmm = init_mmm(env);
	init_stack_b(env, mmm.min, mmm.mid, mmm.max);
	if (env->a_head->val == mmm.min)
		a_head = env->a_head;
	else
		a_head = env->a_head->next;
	while (env->b_size != 0)
	{
		make_scores(env);
		sort_by_score(env);
	}
	last_sort(env, a_head);
}
