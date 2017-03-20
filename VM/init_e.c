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

void init_e(t_env *e, int ac, char **av)
{
	e->player_amount = ac;
	e->files = av;
	e->cycle = 0;
	e->lives = 0;
	e->check = 0;
	e->cycles_to_die = CYCLE_TO_DIE;
	e->player = malloc(sizeof(t_player) * ac);
	ft_bzero(e->arena, (MEM_SIZE));
	ft_files_to_string(e);
	set_op_tab(e);
}
