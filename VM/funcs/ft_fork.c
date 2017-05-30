/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:07:21 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/30 19:48:16 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void		ft_clone_cursor_reg(int *dest, int *src)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		dest[i] = src[i];
}

t_cursor	*ft_clone_cursor(t_cursor *cursor, t_cursor *fork_cursor)
{
	fork_cursor = malloc(sizeof(t_cursor));
	if (fork_cursor == NULL)
		return (NULL);
	fork_cursor->counter = 0;
	fork_cursor->player = cursor->player;
	fork_cursor->carry = cursor->carry;
	fork_cursor->cycle = 1;
	fork_cursor->life = cursor->life;
	fork_cursor->dead = cursor->dead;
	fork_cursor->color = cursor->color;
	ft_clone_cursor_reg(fork_cursor->reg, cursor->reg);
	fork_cursor->running = 0;
	fork_cursor->index = cursor->index;
	fork_cursor->next = NULL;
	fork_cursor->prev = NULL;
	return (fork_cursor);
}

void		ft_fork_both(t_env *e, t_cursor *cursor, int lfork)
{
	t_cursor	*fork_cursor;
	t_cursor	*temp;
	t_cursor	*head_temp;
	int			index_extra;

	temp = e->head;
	fork_cursor = NULL;
	index_extra = get_dir(e, cursor, 1, 2);
	fork_cursor = ft_clone_cursor(cursor, fork_cursor);
	head_temp = e->head->prev;
	temp = head_temp->prev;
	head_temp->prev = fork_cursor;
	fork_cursor->prev = temp;
	temp->next = fork_cursor;
	fork_cursor->next = head_temp;
	e->cursors += 1;
	ft_update_cursor(e, cursor, 3);
	if (lfork)
		ft_update_cursor(e, fork_cursor, MODA(index_extra));
	else
		ft_update_cursor(e, fork_cursor, MODX(index_extra));
}

void		ft_fork(t_env *e, t_cursor *cursor)
{
	ft_fork_both(e, cursor, 0);
}
