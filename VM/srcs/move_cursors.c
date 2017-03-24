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
	int end;
	t_cursor *cursor;
	end = 1;
	cursor = e->head;
	ft_init_ncurses();
	ft_print_arena(e);
	while (end)
	{
		if(cursor->counter)
			ft_adjust_cycle_macro(e, cursor, &end);
		else
		{
			if(!cursor->running)
				ft_add_cycle(e, cursor);
			else
				ft_cycle_end_and_execute(e, cursor);
		}
		cursor = cursor->next;
		cursor->index = cursor->index % MEM_SIZE;
		ft_update_cursor(e, cursor, 5);
	}
}
