/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:17:23 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/16 16:37:19 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_clear(t_env **env)
{
	t_elem	*mover;
	t_elem	*free_elem;

	if ((*env)->a_head->next != NULL)
		mover = (*env)->a_head->next;
	else
		mover = (*env)->a_head;
	while (mover != (*env)->a_head && mover != NULL)
	{
		free_elem = mover;
		mover = mover->next;
		free(free_elem);
	}
	if ((*env)->array != NULL)
		free((*env)->array);
	free((*env)->a_head);
	free(*env);
	*env = NULL;
	exit(0);
}

void	full_clear_err(t_env **env)
{
	t_elem	*mover;
	t_elem	*free_elem;

	if ((*env)->a_head->next != NULL)
		mover = (*env)->a_head->next;
	else
		mover = (*env)->a_head;
	while (mover != (*env)->a_head)
	{
		free_elem = mover;
		mover = mover->next;
		free(free_elem);
	}
	if ((*env)->array != NULL)
		free((*env)->array);
	free((*env)->a_head);
	free(*env);
	free(env);
	*env = NULL;
	ft_put_error();
}
