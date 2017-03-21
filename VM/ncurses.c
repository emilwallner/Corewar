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

void ft_init_ncurses(void)
{
	initscr();
	noecho();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(-1, COLOR_BLACK, COLOR_CYAN);
	init_pair(-2, COLOR_BLACK, COLOR_BLUE);
	init_pair(-3, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(-4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(-5, COLOR_BLACK, COLOR_RED);
	init_pair(-6, COLOR_BLACK, COLOR_YELLOW);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_GREEN);
	start_color();
	curs_set(FALSE);
}
