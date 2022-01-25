/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:05:30 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/25 21:18:58 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_elem	t_elem;
typedef struct s_env	t_env;
typedef struct s_mmm	t_mmm;

# define MAX_INT_DIGITS 10
# define FALSE	0
# define TRUE	1

struct s_elem
{
	long	val;
	long	elem_score;
	t_elem	*prev;
	t_elem	*next;
};

struct	s_env
{
	t_elem	*a_head;
	t_elem	*b_head;
	long	a_size;
	long	b_size;
	long	*array;
};

struct s_mmm
{
	long	min;
	long	mid;
	long	max;
};

void	ft_putstr(char *str);
t_elem	*create_elem(long val);
void	args_checker(int argc, char **argv);
int		check_for_doubles_helper(int *nums, int amount_of_nums);
long	*nums_builder(char *str, int amount_of_nums);
int		ft_atoi(char *str);
int		ft_isdigit(char *str);
void	ft_put_error(void);
void	sa(t_elem **stack);
void	sb(t_elem **stack);
void	ss(t_env *env);
void	swap_two(t_elem **stack);
void	pa(t_env *env);
void	push_to_a(t_env *env);
void	push_to_small_a(t_env *env);
void	pb(t_env *env);
void	push_to_b(t_env *env);
void	push_to_small_b(t_env *env);
void	ra(t_elem **stack, int times);
void	rra(t_elem **stack, int times);
void	rb(t_elem **stack, int times);
void	rrb(t_elem **stack, int times);
void	rr(t_env *env, long times);
void	rrr(t_env *env, long times);
void	rotate(t_elem **stack, int is_reverse);
void	sort_this(t_env *env);
void	sort_two(t_elem **stack, int is_b);
void	sort_three_a(t_elem **stack);
void	sort_three_b(t_elem **stack);
void	small_sort(t_env *env);
void	sort_array(t_env *env, long low, long high, long *swaps);
void	full_sort(t_env *env);
void	full_clear(t_env **env);
void	full_clear_err(t_env **env);
void	init_stack(char **argv, t_env *env);
void	init_array(t_env *env);
t_env	*init_single_arg(char *arg);
void	init_stack_b(t_env *env, long min, long mid, long max);
t_env	*init_env(void);
t_mmm	init_mmm(t_env *env);
void	make_scores(t_env *env);
void	last_sort(t_env *env, t_elem *head);

#endif
