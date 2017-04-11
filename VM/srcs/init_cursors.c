/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cursors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/30 20:15:49 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_cursor	*ft_create_cursor(int i, t_env *e)
{
	t_cursor	*newcursor;

	newcursor = malloc(sizeof(t_cursor));
	if (newcursor == NULL)
		return (NULL);
	newcursor->counter = 0;
	newcursor->player = i;
	newcursor->life = 0;
	newcursor->dead = 0;
	newcursor->carry = 0;
	newcursor->cycle = 0;
	init_reg(newcursor);
	newcursor->reg[0] = e->player[i].nbr;
	newcursor->color = (1 + i % 6) + 6;
	newcursor->running = 0;
	newcursor->index = e->player[i].index_start;
	newcursor->next = NULL;
	newcursor->prev = NULL;
	return (newcursor);
}

t_cursor	*ft_add_cursor_to_stack(t_env *e, t_cursor *stack, int i)
{
	while (stack && stack->next)
		stack = stack->next;
	stack->next = ft_create_cursor(i, e);
	stack->next->prev = stack;
	return (stack);
}

t_cursor	*ft_create_cursor_list(t_env *e)
{
	int			i;
	t_cursor	*stack;
	t_cursor	*head;

	stack = NULL;
	i = e->player_amount - 1;
	while (i > -1)
	{
		if (!stack)
		{
			stack = ft_create_cursor(i, e);
			head = stack;
		}
		else
			stack = ft_add_cursor_to_stack(e, stack, i);
		i--;
	}
	return (head);
}

void		init_color_cursor(t_env *e)
{
	t_cursor *cursor;

	cursor = e->head;
	while (!cursor->counter)
	{
		ft_update_cursor(e, cursor, 0);
		cursor = cursor->next;
	}
}

void		ft_init_cursor(t_env *e)
{
	t_cursor	*stack;

	stack = ft_create_cursor_list(e);
	e->head = stack;
	while (stack && stack->next)
		stack = stack->next;
	stack->next = ft_create_cursor(0, e);
	stack->next->counter = 1;
	stack->next->next = e->head;
	stack->next->prev = stack;
	e->head->prev = stack->next;
	init_color_cursor(e);
}
