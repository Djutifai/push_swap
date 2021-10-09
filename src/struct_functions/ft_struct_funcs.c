#include "push_swap.h"

t_elem	*create_elem(long val)
{
	t_elem *elem;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return (NULL);
	elem->val = val;
	elem->elem_score = 0;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

long	init_stack(char **argv, t_elem **stack)
{
	long 	num;
	long	i;
	t_elem *head;
	t_elem *move;
	t_elem *temp;

	i = 1;
	num = ft_atoi(argv[i++]);
	head = create_elem(num);
	move = head;
	while (argv[i])
	{
		temp = move;
		move = move->next;
		num = ft_atoi(argv[i++]);
		move = create_elem(num);
		move->prev = temp;
		temp->next = move;
	}
	move->next = head;
	head->prev = move;
	*stack = head;
	return (i - 1);
}

t_env *init_env()
{
	t_env *env;
	
	env = malloc(sizeof(*env));
	if (env == NULL)
		ft_put_error();
	env->a_size = 0;
	env->b_size = 0;
	return (env);
}