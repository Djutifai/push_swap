/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:42:02 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/25 21:17:56 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line_bonus.h"

static int	ft_strcmp(char *str, char *dest)
{
	while ((*str != '\0' && *dest != '\0' ) && *str == *dest)
	{
		str++;
		dest++;
	}
	if (*str == *dest)
		return (1);
	else
		return (0);
}

static int	do_instruction(char *str, t_env *env)
{
	if (ft_strcmp(str, "pa"))
		pa(env);
	else if (ft_strcmp(str, "pb"))
		pb(env);
	else if (ft_strcmp(str, "ra"))
		ra(&env->a_head, 1);
	else if (ft_strcmp(str, "rra"))
		rra(&env->a_head, 1);
	else if (ft_strcmp(str, "rb"))
		rb(&env->b_head, 1);
	else if (ft_strcmp(str, "rrb"))
		rrb(&env->b_head, 1);
	else if (ft_strcmp(str, "sa"))
		sa(&env->a_head);
	else if (ft_strcmp(str, "sb"))
		sb(&env->b_head);
	else if (ft_strcmp(str, "rr"))
		rr(env, 1);
	else if (ft_strcmp(str, "rrr\n"))
		rrr(env, 1);
	else
		return (0);
	return (1);
}

static int	is_sorted(t_env *env)
{
	t_elem	*elem;
	int		i;

	if (env->b_size != 0)
		return (0);
	i = 0;
	elem = env->a_head;
	while (i < env->a_size - 1)
	{
		if (elem->val > elem->next->val)
			return (0);
		i++;
		elem = elem->next;
	}
	return (1);
}

static int	check(t_env *env)
{
	char	*str;

	while (get_next_line(0, &str) > 0)
	{
		if (!do_instruction(str, env))
		{
			write(1, "Error!\n", 7);
			free (str);
			return (0);
		}
		free(str);
	}
	if (str)
		free(str);
	return (1);
}

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
	if (check(env))
	{
		if (is_sorted(env))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	full_clear(&env);
}
