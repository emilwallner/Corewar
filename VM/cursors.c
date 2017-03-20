/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/20 17:08:18 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_cursor		*ft_create_cursor(int i, t_env *e)
{
	t_cursor	*newcursor;

	newcursor = malloc(sizeof(t_cursor));
	if (newcursor == NULL)
		return (NULL);
	newcursor->counter = 0;
	newcursor->player = i;
	newcursor->id = 0;
	newcursor->carry = 0;
	newcursor->cycle = 0;
	newcursor->running = 0;
	newcursor->comnd_len = 1;
	newcursor->index = e->player[i].index_start;
	newcursor->next = NULL;
	return (newcursor);
}

t_cursor		*ft_add_cursor_to_stack(t_cursor *stack, int i, t_env *e)
{
	if(!stack)
	{
		stack = ft_create_cursor(i, e);
		newcursor->counter = 1;
		e->head = stack;
	}
	else
	{
		while (stack && stack->next)
			stack = stack->next;
		stack->next = ft_create_cursor(i, e);
	}
	return (stack);
}

void		ft_init_cursor(t_env *e)
{
	int 		i;
	t_cursor	*stack;

	i = -1;
	stack = NULL;
	while(++i < e->player_amount)
		stack = ft_add_cursor_to_stack(stack, i, e);
	while (stack && stack->next)
		stack = stack->next;
	stack->next = e->head;
}
