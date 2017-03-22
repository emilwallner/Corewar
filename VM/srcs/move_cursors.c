/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/20 17:07:41 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_update_cursor(t_env *e, t_cursor *cursor, int i)
{
	e->a[cursor->index].color = e->a[cursor->index].prevcolor;
		cursor->index += i;
	e->a[cursor->index].color = cursor->color;
}

void 	ft_move_cursors(t_env *e)
{
	int i;
	int end;
	t_cursor *cursor;
	end = 1;
	cursor = e->head;
	i = 0;
	while(!cursor->counter)
	{
		ft_update_cursor(e, cursor, 0);
		cursor = cursor->next;
	}
	cursor = cursor->next;
	ft_init_ncurses();
	while (end)
	{
		if(cursor->counter)
			ft_adjust_cycle(e, cursor, &end);
		else
		{
			if(!cursor->running)
				ft_store_and_check_operation(e, cursor);
			else
				ft_cycle_break(e, cursor);
			cursor->index = cursor->index % MEM_SIZE;
			cursor = cursor->next;
			i++;
		}
	}
}
