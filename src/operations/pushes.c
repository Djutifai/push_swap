#include "push_swap.h"

void	push_to_a(t_env *env)
{
	t_elem	*temp;

	if (env->b_head == NULL)
		return ;
	temp = env->b_head;
	env->b_head = temp->next;
	temp->next = env->a_head;
	env->a_head->prev->next = temp;
	if (env->b_head != NULL)
		env->b_head->prev = temp->prev;
	temp->prev = env->a_head->prev;
	env->a_head->prev = temp;
	env->a_head = temp;
	if (env->b_size == 2)
	{
		env->b_head->prev = NULL;
		env->b_head->next = NULL;
	}
	else if (env->b_size > 2)
		env->b_head->prev->next = env->b_head;
	env->a_size++;
	env->b_size--;
}

void	push_to_b(t_env *env)
{
	t_elem	*temp;

	if (env->a_head == NULL)
		return ;
	temp = env->a_head;
	env->a_head = temp->next;
	temp->next = env->b_head;
	env->b_head->prev->next = temp;
	if (env->a_head != NULL)
		env->a_head->prev = temp->prev;
	temp->prev = env->b_head->prev;
	env->b_head->prev = temp;
	env->b_head = temp;
	if (env->a_size == 2)
	{
		env->a_head->prev = NULL;
		env->a_head->next = NULL;
	}
	else if (env->a_size > 2)
		env->a_head->prev->next = env->a_head;
	env->a_size--;
	env->b_size++;
}
