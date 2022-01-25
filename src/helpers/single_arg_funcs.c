/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_arg_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:26:53 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/25 21:21:06 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_for_doubles(char *str, int amount_of_nums)
{
	long	*nums;
	int		i;
	int		j;

	nums = nums_builder(str, amount_of_nums);
	i = 0;
	while (i < amount_of_nums)
	{
		j = 0;
		while (j < i)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(nums);
	return (0);
}

static int	is_digit_on_steroids(char *str, int l, int r)
{
	int	minus_counter;
	int	plus_counter;

	minus_counter = 0;
	plus_counter = 0;
	while (l < r && (str[l] == '-' || str[l] == '+'))
	{
		if (str[l] == '-')
			minus_counter++;
		else if (str[l] == '+')
			plus_counter++;
		l++;
	}
	if (minus_counter > 1 || plus_counter > 1 || \
		(plus_counter == 1 && minus_counter == 1))
		return (0);
	while (l < r && str[l] && str[l] >= '0' && str[l] <= '9')
		l++;
	if (l != r)
		return (0);
	return (1);
}

static void	init_stack_single(long *nums, int amount_of_nums, t_env *env)
{
	int		i;
	t_elem	*head;
	t_elem	*temp;
	t_elem	*move;

	i = 0;
	head = create_elem(nums[i++]);
	env->a_head = head;
	if (!head)
		full_clear_err(&env);
	move = head;
	while (i < amount_of_nums)
	{
		temp = move;
		move = move->next;
		move = create_elem(nums[i++]);
		if (!move)
			full_clear_err(&env);
		move->prev = temp;
		temp->next = move;
	}
	move->next = head;
	head->prev = move;
	env->a_size = amount_of_nums;
	init_array(env);
}

static int	single_arg_parser(char *str)
{
	size_t	i;
	size_t	l;
	size_t	nums;

	nums = 0;
	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9'))
		{
			l = i;
			while (str[i] && str[i] != ' ')
				i++;
			if (!is_digit_on_steroids(str, l, i))
				ft_put_error();
			else
				nums++;
		}
		i++;
	}
	if (check_for_doubles(str, nums))
		ft_put_error();
	return (nums);
}

t_env	*init_single_arg(char *arg)
{
	t_env	*env;
	size_t	amount_of_nums;
	long	*nums;

	amount_of_nums = single_arg_parser(arg);
	env = init_env();
	nums = nums_builder(arg, amount_of_nums);
	init_stack_single(nums, amount_of_nums, env);
	free(nums);
	return (env);
}
