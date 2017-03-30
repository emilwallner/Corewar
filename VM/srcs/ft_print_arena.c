/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:04:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 20:43:16 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void	ft_print_bonus(t_env *e)
{
	int i;
	i = 0;

	if(e->tot_cycle > 0)
		getch();
	erase();
	while(i < MEM_SIZE)
	{
		if(e->a[i].new_color_count > 0)
			attron(A_BOLD);
		attron(COLOR_PAIR(e->a[i].color));
		printw("%02x", 0xFF & e->a[i].hex);
		//addch(ACS_DIAMOND);
		attroff(COLOR_PAIR(e->a[i].color));
		if(e->a[i].new_color_count > 0)
		{
			attroff(A_BOLD);
			e->a[i].new_color_count -= 1;
		}
		printw(" ");
		if ((i + 1) % (128 / 2) == 0)
			printw("\n");
		i++;
	}
	attron(COLOR_PAIR(14));
	printw("\nCycle: %d \n", e->tot_cycle);
	printw("Cursors: %d \n", e->cursors);
	printw("Number of lives: %d \n", e->lives);
	attroff(COLOR_PAIR(14));
	refresh();
}


void	ft_print_normal(t_env *e)
{
	int i;
	int hex;
	int k;

	k = -1;
	hex = 0;
	i = 0;

	ft_printf("Introducing contestants...\n");
	while(++k < e->player_amount)
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", ABS(e->player[k].nbr), e->player[k].inst_len, e->player[k].name, e->player[k].comment);
	while(i < MEM_SIZE)
	{
		if ((i) % (128 / 2) == 0)
			ft_printf("0x%04x : ", hex);
		ft_printf("%02x ", 0xFF & e->a[i].hex);
		if ((i + 1) % (128 / 2) == 0)
		{
			ft_printf("\n");
			hex += 64;
		}
		i++;
	}
	ft_exit(e, -2);
}

void	ft_print_arena(t_env *e)
{
	if(e->bonus)
		ft_print_bonus(e);
	if(e->dump)
	{
		if(e->tot_cycle >= e->dump_value)
			ft_print_normal(e);
	}
}
