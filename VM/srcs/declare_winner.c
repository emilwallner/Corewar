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

/*
** Have one option with bonus, and one without
*/

void ft_declare_winner(t_env *e)
{
	attron(COLOR_PAIR(8));
	printw("The winner is: Player %d\n", 0xFF & e->winner);
	attroff(COLOR_PAIR(8));
	refresh();
	getch();
	endwin();
}
