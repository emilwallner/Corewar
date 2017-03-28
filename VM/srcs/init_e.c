/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/19 18:37:40 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void init_players(t_env *e)
{
	int i;

	i = 0;
	while(i < e->player_amount)
	{
		e->player[i].len = 0;
		e->player[i].live = 0;
		i++;
	}
}

void ft_szero(t_env *e)
{
	int i;

	i = 0;
	while(i < MEM_SIZE)
	{
		e->a[i].hex = 0;
		e->a[i].color = 12;
		e->a[i].prevcolor = 12;
		e->a[i].occupied = 0;
		e->a[i].new_color_count = 0;
		//e->a[i].light_color = 12;
		i++;
	}
}

void init_e(t_env *e, int ac, char **av)
{
	e->player_amount = ac - 1;
	e->files = av;
	e->cycle = 0;
	e->lives = 0;
	e->bonus = 1;
	e->winner = 1;
	e->check = 0;
	e->tot_cycle = 0;
	e->cursors = e->player_amount;
	e->head = NULL;
	e->cycles_to_die = CYCLE_TO_DIE;
	init_players(e);
	ft_szero(e);
	ft_files_to_string(e);
	set_op_tab(e);
}
