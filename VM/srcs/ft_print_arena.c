/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:04:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 16:53:27 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_arena(t_env *e)
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
	// printw("Index 1: %d Hex %d\n", e->head->index, e->a[e->head->index].hex);
	// printw("Index 2: %d Hex %d\n", e->head->next->index, e->a[e->head->next->index].hex);
	// printw("Index 3: %d Hex %d\n", e->head->next->next->index, e->a[e->head->next->next->index].hex);
	// printw("Player 1 name: %s \n", e->player[0].name);
	// printw("Player 1 comment: %s \n", e->player[0].comment);
	// printw("Player 3 name: %s \n", e->player[2].name);
	printw("Cursors: %d \n", e->cursors);
	// printw("\nNumber of cycles to die: %d \n", e->cycles_to_die);
	// printw("\nNumber of checks: %d \n", e->check);
	printw("Number of lives: %d \n", e->lives);
	// printw("\nNumber of lives limit: %d \n", NBR_LIVE);
	// printw("\nNumber of max checks: %d \n", MAX_CHECKS);
	// printw("\nNumber of player 0: %d \n", e->player[0].index_start);
	// printw("\nNumber of player 1: %d \n", e->player[1].index_start);
	// printw("\nNumber of player 2: %d \n", e->player[2].index_start);
	// printw("\nReg 2 : %d \n", e->head->reg[2]);
	attroff(COLOR_PAIR(14));
	refresh();
	//usleep(500000);
}
