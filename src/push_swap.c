/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:02 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/25 21:19:43 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2)
		env = init_single_arg(argv[1]);
	else
	{
		args_checker(argc, argv);
		env = init_env();
		init_stack(argv, env);
	}
	sort_this(env);
	full_clear(&env);
}
