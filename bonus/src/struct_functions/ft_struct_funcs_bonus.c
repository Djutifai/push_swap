/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_funcs_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:36:36 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/15 16:39:45 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	init_array(t_env *env)
{
	long	i;
	t_elem	*mover;
	long	swaps;

	swaps = 0;
	i = 0;
	mover = env->a_head->next;
	env->array = malloc(sizeof(*(env->array)) * env->a_size);
	if (env->array == NULL)
		full_clear_err(&env);
	while (mover != env->a_head)
	{
		env->array[i++] = mover->val;
		mover = mover->next;
	}
	env->array[i] = mover->val;
	sort_array(env, 0, env->a_size - 1, &swaps);
	if (swaps == 0)
		exit(0);
}

t_elem	*create_elem(long val)
{
	t_elem	*elem;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return (NULL);
	elem->val = val;
	elem->elem_score = 0;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	init_stack(char **argv, t_env *env)
{
	long	i;
	t_elem	*head;
	t_elem	*move;
	t_elem	*temp;

	i = 1;
	head = create_elem(ft_atoi(argv[i++]));
	env->a_head = head;
	if (!head)
		full_clear_err(&env);
	move = head;
	while (argv[i])
	{
		temp = move;
		move = move->next;
		move = create_elem(ft_atoi(argv[i++]));
		if (!move)
			full_clear_err(&env);
		move->prev = temp;
		temp->next = move;
	}
	move->next = head;
	head->prev = move;
	env->a_size = i - 1;
	init_array(env);
}

t_env	*init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(*env));
	if (env == NULL)
		ft_put_error();
	env->a_size = 0;
	env->b_size = 0;
	return (env);
}
