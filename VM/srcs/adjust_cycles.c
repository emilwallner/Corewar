/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_cycles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 19:26:42 by ewallner          #+#    #+#             */
/*   Updated: 2017/04/11 19:26:48 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void (*g_func_ptr[17])(t_env *e, t_cursor *cursor) =
{
	ft_live, ft_live, ft_ld, ft_st, ft_add, ft_sub, ft_and, ft_or,
	ft_xor, ft_zjmp, ft_ldi, ft_sti, ft_fork, ft_lld, ft_lldi,
	ft_lfork, ft_aff
};

void	ft_clear_player_lives(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->player_amount)
		e->player[i].live = 0;
}

void	ft_kill_cursors(t_cursor *cursor)
{
	t_cursor *temp;

	temp = cursor;
	while (temp && !temp->counter)
	{
		if (!temp->life)
			temp->dead = 1;
		temp->life = 0;
		temp = temp->next;
	}
}

void	ft_new_cycle(t_env *e, int *end)
{
	ft_kill_cursors(e->head);
	if (e->lives == 0 || (e->cycles_to_die - CYCLE_DELTA) < 1)
		*end = 0;
	if (e->lives < NBR_LIVE)
		e->check += 1;
	if (e->check == MAX_CHECKS || e->lives >= NBR_LIVE)
	{
		e->cycles_to_die -= CYCLE_DELTA;
		if (e->cycles_to_die < 0)
			e->cycles_to_die = 0;
		e->lives = 0;
		e->check = 0;
		ft_clear_player_lives(e);
	}
	e->lives = 0;
	e->cycle = 0;
}

void	ft_adjust_cycle_macro(t_env *e, t_cursor *cursor, int *end)
{
	if (e->cycle == e->cycles_to_die)
		ft_new_cycle(e, end);
	else
	{
		e->cycle += 1;
		e->tot_cycle += 1;
	}
	cursor = cursor->next;
	ft_print_arena(e);
}

void	ft_cycle_end_and_execute(t_env *e, t_cursor *cursor)
{
	if (cursor->cycle == 0)
	{
		if (ft_check_args(*e, *cursor))
			(*g_func_ptr[(int)e->a[cursor->index].hex])(e, cursor);
		else
			ft_update_cursor(e, cursor, 1);
		cursor->running = 0;
	}
	else
		cursor->cycle -= 1;
}
