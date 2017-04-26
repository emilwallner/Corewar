/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:04:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/31 22:10:30 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_lives(t_env *e, int i)
{
	int k;
	int cycles;

	attron(COLOR_PAIR(e->player[i].color));
	cycles = (e->player[i].live < 161) ? e->player[i].live : 161;
	k = -1;
	printw("\nLives for %-15s", e->player[i].name);
	printw("%-5d", e->player[i].live);
	while (++k < cycles)
		addch(ACS_CKBOARD);
	attroff(COLOR_PAIR(e->player[i].color));
}
