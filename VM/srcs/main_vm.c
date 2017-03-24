/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/24 17:24:46 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int ac, char **av)
{
	t_env e;

	init_e(&e, ac, av);
	// ft_parsing(&e, ac);
 // 	ft_build_arena(&e, ac);
	// ft_init_cursor(&e);
	// ft_move_cursors(&e);
	// ft_declare_winner(&e);
	ft_debug(e);
	return(0);
}
