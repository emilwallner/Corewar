/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/31 19:26:28 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_players(t_env *e)
{
	int i;

	i = 0;
	while (i < e->player_amount)
	{
		e->player[i].live = 0;
		e->player[i].color = 1 + (i % 6);
		i++;
	}
}

void	ft_szero(t_env *e)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		e->a[i].hex = 0;
		e->a[i].color = 12;
		e->a[i].prevcolor = 12;
		e->a[i].occupied = 0;
		e->a[i].new_color_count = 0;
		i++;
	}
}

void	init_e(t_env *e, char **av)
{
	e->files = av;
	e->cycle = 0;
	e->lives = 0;
	e->bonus = 0;
	e->dump = 0;
	e->winner = 0;
	e->check = 0;
	e->tot_cycle = 0;
	e->head = NULL;
	e->cycles_to_die = CYCLE_TO_DIE;
	ft_szero(e);
	set_op_tab(e);
}
