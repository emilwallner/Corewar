/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:04:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/19 16:35:15 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	*player;
t_cursor	*head;
t_arena		a[MEM_SIZE];
int 		cycle;
int			lives;
int			check;
int			winner;
int 		last_alive;
int			cycles_to_die;
char		**strings;
char		arena[MEM_SIZE];
int			player_amount;
char		**files;
t_op		op_tab[17];

void	ft_print_arena(t_env *e)
{
	int i;
	(void)e;
	i = 0;

	erase();
	while(i < MEM_SIZE)
	{
		attron(COLOR_PAIR(e->a[i].color));
		printw("%02x", 0xFF & e->a[i].hex);
		attroff(COLOR_PAIR(e->a[i].color));
		printw(" ");
		if ((i + 1) % (128 / 2) == 0)
			printw("\n");
		i++;
	}
	attron(COLOR_PAIR(14));
	// printw("\nNumber of cycles: %d \n", e->cycle);
	// printw("\nNumber of cycles to die: %d \n", e->cycles_to_die);
	// printw("\nNumber of checks: %d \n", e->check);
	// printw("\nNumber of lives: %d \n", e->lives);
	// printw("\nNumber of lives limit: %d \n", NBR_LIVE);
	// printw("\nNumber of max checks: %d \n", MAX_CHECKS);
	printw("\nNumber of player 0: %d \n", e->player[0].index_start);
	// printw("\nNumber of player 1: %d \n", e->player[1].index_start);
	// printw("\nNumber of player 2: %d \n", e->player[2].index_start);
	printw("\nReg 2 : %d \n", e->head->reg[2]);
	attroff(COLOR_PAIR(14));
	refresh();
	usleep(500000);
	getch();
}
