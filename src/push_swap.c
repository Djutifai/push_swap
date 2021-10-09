/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:02 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/09 16:37:31 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env	*env;
	t_elem	*elem;
	t_elem	*move;
	t_elem	*belem;

	env = malloc(sizeof(*env));
	args_checker(argc, argv);
	//env = init_env();
	elem = init_stack(argv);
	env->a_head = elem;
	belem = create_elem(55);
	env->b_head = belem;
	t_elem *temp = create_elem(10);
	env->b_head->next = temp;
	env->b_head->prev = temp;
	temp->next = env->b_head;
	temp->prev = env->b_head;
	int i = 0;
	env->a_size = 3;
	env->b_size = 2;
	sort_three(&env->a_head);
	push_to_a(env);
	push_to_b(env);
	printf("value - %ld\n", env->a_head->val);
	move = env->a_head;
	while (i < env->a_size)
	{
		printf("%ld\n", move->val);
		move = move->next;
		i++;
	}
}
