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

t_elem	*init_stack(char **argv)
{
	long 	num;
	long	i;
	t_elem *head;
	t_elem *move;
	t_elem *temp;

	i = 1;
	num = ft_atoi(argv[i++]);
	if (num < INT_MIN || num > INT_MAX)
		ft_put_error();	
	head = create_elem(num);
	move = head;
	while (argv[i])
	{
		temp = move;
		move = move->next;
		num = ft_atoi(argv[i++]);
		if (num < INT_MIN || num > INT_MAX)
			ft_put_error();
		move = create_elem(num);
		move->prev = temp;
		temp->next = move;
	}
	move->next = head;
	head->prev = move;
	return (head);
}

t_env *init_env(long size)
{
	t_env *env;
	
	env = malloc(sizeof(*env));
	if (env == NULL)
		return (NULL);
	env->a_size = size;
	env->b_size = size;
//	env->a_head;
	return (env);
}