/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:37:28 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/16 17:40:31 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static long	get_a_score(t_elem *a_head, long value)
{
	long	lscore;
	long	rscore;
	t_elem	*mover;

	lscore = 0;
	rscore = 0;
	mover = a_head;
	while (!(mover->prev->val < value && value < mover->val))
	{
		mover = mover->next;
		++lscore;
	}
	mover = a_head;
	while (!(mover->prev->val < value && value < mover->val))
	{
		mover = mover->prev;
		++rscore;
	}
	if (lscore < rscore)
		return (lscore);
	return (rscore);
}

static long	get_b_score(t_elem *b_head, t_elem *stack_b)
{
	long	lscore;
	long	rscore;
	t_elem	*mover;

	lscore = 0;
	rscore = 0;
	mover = stack_b;
	while (mover != b_head)
	{
		mover = mover->next;
		++lscore;
	}
	mover = stack_b;
	while (mover != b_head)
	{
		mover = mover->prev;
		++rscore;
	}
	if (lscore < rscore)
		return (lscore);
	return (rscore);
}

void	make_scores(t_env *env)
{
	t_elem	*move_a;
	t_elem	*move_b;

	move_a = env->a_head;
	if (env->b_size > 1)
		move_b = env->b_head->next;
	else
		move_b = env->b_head;
	while (move_b != env->b_head)
	{
		move_b->elem_score = get_a_score(env->a_head, move_b->val) + \
			get_b_score(env->b_head, move_b);
		move_b = move_b->next;
	}
	env->b_head->elem_score = get_a_score(env->a_head, move_b->val) + \
			get_b_score(env->b_head, move_b);
}
