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

int		check_if_valid(t_env *e, t_cursor *cursor)
{
	if(e->a[cursor->index].hex > 0 && e->a[cursor->index].hex < 17)
		return (1);
	else
		return (0);
}

void ft_store_and_check_operation(t_env *e, t_cursor *cursor)
{
	if(check_if_valid(e, cursor))
	{
		//ft_copy_command(e);
		cursor->cycle = e->op_tab[cursor->index].cycles;
		cursor->running = 1;
		//cursor->comnd_len = calc_len_of_op(cursor);
		cursor->comnd_len = 5;
	}
	else
		ft_update_cursor(e, cursor, 1);
}

void 	ft_move_cursors(t_env *e)
{
	int i;
	int end;
	t_cursor *cursor;

	end = 1;
	cursor = e->head;
	i = 0;
	while (end)
	{
		ft_init_ncurses();
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
