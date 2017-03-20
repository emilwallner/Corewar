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

void ft_new_cycle(t_env *e)
{
	if(e->lives = 0)
		end = 0;
	if(e->lives < NBR_LIVE)
		e->check += 1;
	if(e->check == MAX_CHECKS)
	{
		e->cycles_to_die -= CYCLE_DELTA;
		e->lives = 0;
	}
	else
	{
		e->check = 0;
		e->lives = 0;
	}
}

void 	execute_command(cursor);
{

}

void 	ft_move_cursors(t_env *e)
{
	int i;
	int end;
	t_cursor *cursor;

	cursor = e->head;
	i = 0;
	while (end)
	{
		if(cursor->counter)
		{
			if(e->cycle == e->cycles_to_die)
				ft_new_cycle(e);
			else
				e->cycle += 1;
			cursor = cursor->next;
		}
		else
		{
			if(!cursor->running)
				{
					if(check_if_valid(cursor))
					{
						ft_copy_command(e);
						cursor->cycle = g_op_tab[cursor->index].cycles;
						cursor->running = 1;
						cursor->comnd_len = calc_len_of_op(cursor);
					}
					else
						cursor->index += 1;
				}
			else
			{
				if(cursor->cycle == 0)
				{
					func_ptr[cursor->index](copied code, cursor);
					cursor->running = 0;
					cursor->index += comnd_len;
				}
				else
					cursor->cycle -= 1;
			}
			ft_check_index_max(cursor); //mod 
			cursor = cursor->next;
			i++;
		}
	}
}


// cursor->index += 1;
// if(cursor->index == MEM_SIZE + 1)
// 	cursor->index = 0;
