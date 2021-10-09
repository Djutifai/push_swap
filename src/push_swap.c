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

	args_checker(argc, argv);
	env = init_env();
	env->a_size = init_stack(argv, &elem);
	t_elem *FORIGOR;
	env->b_size = init_stack(argv, &FORIGOR);
	env->a_head = elem;
	env->b_head = FORIGOR;
	int i = 0;
	printf("HAHAH %ld\n", env->a_size);
	//sort_five(env);
	pa(env);
	move = env->a_head;
	while (i < env->a_size)
	{
		printf("%ld val\n", move->val);
		move = move->next;
		i++;
	}
}
