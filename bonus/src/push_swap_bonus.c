/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:02 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/15 18:07:12 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_str_cmp(char *str, char *sec_str)
{
	int	i;

	i = 0;
	while (str[i] && sec_str[i] && str[i] == sec_str[i])
		i++;
	if (str[i] != sec_str[i])
		return (-1);
	return (1);
}

static void	do_instruction(char *str, t_env *env)
{
	if (ft_str_cmp(str, "pa"))
		pa(env);
	else if (ft_str_cmp(str, "pb"))
		pb(env);
	else if (ft_str_cmp(str, "ra"))
		ra(&env->a_head, 1);
	else if (ft_str_cmp(str, "rra"))
		rra(&env->a_head, 1);
	else if (ft_str_cmp(str, "rb"))
		rb(&env->b_head, 1);
	else if (ft_str_cmp(str, "rrb"))
		rrb(&env->b_head, 1);
	else if (ft_str_cmp(str, "sa"))
		sa(&env->a_head);
	else if (ft_str_cmp(str, "sb"))
		sb(&env->b_head);
	else if (ft_str_cmp(str, "rr"))
		rr(env, 1);
	else if (ft_str_cmp(str, "rrr"))
		rrr(env, 1);
}

static void check(t_env *env)
{
	char *str;
	int	read_bytes;

	read_bytes = get_next_line(1, &str);
	while (read_bytes > 0)
	{
		if 
	}
}

int	main(int argc, char **argv)
{
	t_env	*env;

	args_checker(argc, argv);
	env = init_env();
	init_stack(argv, env);
	sort_this(env);
	full_clear(&env);
}
