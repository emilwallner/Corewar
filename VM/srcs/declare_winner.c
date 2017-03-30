/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/30 20:03:31 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Have one option with bonus, and one without
*/

void	ft_declare_winner(t_env *e)
{
	if (e->bonus)
	{
		attron(COLOR_PAIR(e->winner + 1 % 6));
		printw("Contestant %d, \"%s\", has won !\n",
		e->player[e->winner].nbr, e->player[e->winner].name);
		attroff(COLOR_PAIR(e->winner + 1 % 6));
		refresh();
		getch();
		endwin();
	}
	else
	{
		if (e->dump)
			ft_print_dump_init(e);
		ft_printf("Contestant %d, \"%s\", has won !\n",
		e->player[e->winner].nbr, e->player[e->winner].name);
	}
}
