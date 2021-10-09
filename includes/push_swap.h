#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <stdio.h>
typedef struct s_elem t_elem;
typedef struct s_env t_env;

# define FALSE	0
# define TRUE	1

struct s_elem
{
	long	val;
	long	elem_score;
	t_elem *prev;
	t_elem *next;
};

struct	s_env
{
	t_elem	*a_head;
	t_elem	*b_head;
	long	a_size;
	long	b_size;
};

void	ft_putstr(char *str);
t_elem	*create_elem(long val);
void	args_checker(int argc, char **argv);
int		ft_atoi(char *str);
int		ft_isdigit(char *str);
void	ft_put_error(void);
void	sa(t_elem **stack);
void	sb(t_elem **stack);
void	swap_two(t_elem **stack);
void	pa(t_env *env);
void	push_to_a(t_env *env);
void	pb(t_env *env);
void	push_to_b(t_env *env);
void	ra(t_elem **stack, int times);
void	rra(t_elem **stack, int times);
void	rb(t_elem **stack, int times);
void	rrb(t_elem **stack, int times);
void	rotate(t_elem **stack, int is_reverse);
void	sort_two(t_elem **stack);
void	sort_three(t_elem **stack);
void	sort_five(t_env *env);
long	init_stack(char **argv, t_elem **stack);
t_env	*init_env(void);

#endif
