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

void ft_new_cycle(t_env *e, int *end)
{
	if(e->lives == 0)
		end -= 1;
	if(e->lives < NBR_LIVE)
		e->check += 1;
	if(e->check == MAX_CHECKS || e->lives >= NBR_LIVE)
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

void ft_adjust_cycle(t_env *e, t_cursor *cursor, int *end)
{
	if(e->cycle == e->cycles_to_die)
		ft_new_cycle(e, end);
	else
		e->cycle += 1;
	cursor = cursor->next;
	clear();
	ft_build_vm(e, e->player_amount);
}

void ft_cycle_break(t_cursor *cursor)
{
if(cursor->cycle == 0)
{
	func_ptr[cursor->index](copied code, cursor);
	cursor->running = 0;
	ft_update_cursor(cursor, cursor->comnd_len);
}
else
	cursor->cycle -= 1;
}
