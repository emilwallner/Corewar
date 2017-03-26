/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:07:21 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 17:07:17 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void 	ft_clone_cursor_reg(int *dest, int *src)
{
	int i;

	i = -1;
	while(++i < REG_NUMBER)
		dest[i] = src[i];
}


t_cursor		*ft_clone_cursor(t_cursor *cursor, t_cursor *fork_cursor,
	char index_extra)
{
	fork_cursor = malloc(sizeof(t_cursor));
	if (fork_cursor == NULL)
		return (NULL);
	fork_cursor->counter = 0;
	fork_cursor->player = cursor->player;
	fork_cursor->carry = cursor->carry;
	fork_cursor->cycle = 0;
	fork_cursor->color = cursor->color;
	fork_cursor->running = 0;
	fork_cursor->index = cursor->index + index_extra;
	fork_cursor->index = MODA(fork_cursor->index);
	ft_clone_cursor_reg(fork_cursor->reg, cursor->reg);
	fork_cursor->next = NULL;
	fork_cursor->prev = NULL;
	return (fork_cursor);
}

void	ft_fork(t_env *e, t_cursor *cursor)
{
	t_cursor *fork_cursor;
	t_cursor *stack;
	t_cursor *temp;
	char	index_extra;

	temp = e->head;
	stack = cursor;
	fork_cursor = NULL;
	index_extra = e->a[cursor->index + 1].hex;
	fork_cursor = ft_clone_cursor(cursor, fork_cursor, index_extra);
	temp = e->head->prev;
	e->head->prev = fork_cursor;
	fork_cursor->prev = temp;
	temp->next = fork_cursor;
	fork_cursor->next = e->head;
	e->cursors += 1;
	ft_update_cursor(e, cursor, 2);
}
