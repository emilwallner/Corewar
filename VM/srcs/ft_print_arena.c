/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:04:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/04/15 17:18:11 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_game_stats(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->player_amount)
		ft_print_lives(e, i);
	attron(COLOR_PAIR(14));
	printw("\n\nCycle: %-10d Cursors: %-10d Total Number of lives: %d/%-10d \
	Checks: %d/9 > Decrease cycle to die with: %d     \
	Cycles to die: %d/%d\n\n", e->tot_cycle, e->cursors, NBR_LIVE, e->lives, \
	e->check, CYCLE_DELTA, e->cycles_to_die, e->cycle);
	attroff(COLOR_PAIR(14));
	refresh();
}

void	ft_print_bonus(t_env *e)
{
	int i;

	i = 0;
	erase();
	while (i < MEM_SIZE)
	{
		if (e->a[i].new_color_count > 0)
			attron(A_BOLD);
		attron(COLOR_PAIR(e->a[i].color));
		printw("%02x", 0xFF & e->a[i].hex);
		attroff(COLOR_PAIR(e->a[i].color));
		if (e->a[i].new_color_count > 0)
		{
			attroff(A_BOLD);
			e->a[i].new_color_count -= 1;
		}
		printw(" ");
		if ((i + 1) % (128 / 2) == 0)
			printw("\n");
		i++;
	}
	ft_print_game_stats(e);
}

void	ft_print_dump_init(t_env *e)
{
	int k;

	k = -1;
	ft_printf("Introducing contestants...\n");
	while (++k < e->player_amount)
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", \
		e->player[k].nbr, e->player[k].inst_len, e->player[k].name, \
		e->player[k].comment);
}

void	ft_print_normal(t_env *e)
{
	int	i;
	int	hex;

	hex = 0;
	i = 0;
	ft_print_dump_init(e);
	while (i < MEM_SIZE)
	{
		if ((i) % (32) == 0)
			ft_printf("0x%04x : ", hex);
		ft_printf("%02x ", 0xFF & e->a[i].hex);
		if ((i + 1) % (32) == 0)
		{
			ft_printf("\n");
			hex += 32;
		}
		i++;
	}
	exit(1);
}

void	ft_print_arena(t_env *e)
{
	if (e->bonus)
		ft_print_bonus(e);
	if (e->dump)
	{
		if (e->tot_cycle >= e->dump_value)
			ft_print_normal(e);
	}
}
