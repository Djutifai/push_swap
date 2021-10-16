/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:02 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/16 17:35:45 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	args_checker(argc, argv);
	env = init_env();
	init_stack(argv, env);
	sort_this(env);
	full_clear(&env);
}
