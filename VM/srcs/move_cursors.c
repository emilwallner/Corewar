/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/30 20:19:03 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_update_cursor(t_env *e, t_cursor *cursor, int i)
{
	int	index_temp;

	if (e->a[cursor->index].occupied > 0)
		e->a[cursor->index].occupied -= 1;
	index_temp = cursor->index;
	cursor->index += i;
	cursor->index = MODA(cursor->index);
	e->a[cursor->index].color = cursor->color;
	e->a[cursor->index].occupied += 1;
	if (e->a[index_temp].occupied == 0)
		e->a[index_temp].color = e->a[index_temp].prevcolor;
}

void	ft_move_cursors(t_env *e)
{
	int			end;
	t_cursor	*cursor;

	end = 1;
	cursor = e->head;
	if (e->bonus)
		ft_init_ncurses();
	ft_print_arena(e);
	while (end)
	{
		if (cursor->counter)
			ft_adjust_cycle_macro(e, cursor, &end);
		else
		{
			if (!cursor->dead)
			{
				if (!cursor->running)
					ft_add_cycle(e, cursor);
				else
					ft_cycle_end_and_execute(e, cursor);
			}
		}
		cursor = cursor->next;
	}
}
