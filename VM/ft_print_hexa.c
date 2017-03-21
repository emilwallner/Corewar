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


void	ft_print_hexa(t_env *e)
{
	int i;
	(void)e;
	i = 0;
	while(i < MEM_SIZE)
	{
		attron(COLOR_PAIR(e->a[i].color));
		printw("%02x ", e->a[i].hex);
		if ((i + 1) % (128 / 2) == 0)
			printw("\n");
		i++;
		attroff(COLOR_PAIR(e->a[i].color));
	}
	refresh();
	sleep(1);
}
