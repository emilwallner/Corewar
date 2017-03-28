/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/28 19:27:32 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
void	ft_tests_st(t_env e, t_cursor *cursor);
int			main(int ac, char **av)
{
	t_env e;

	init_e(&e, ac, av);
	ft_parsing(&e, ac);
	ft_build_arena(&e, ac);
	ft_init_cursor(&e);
	ft_move_cursors(&e);
	ft_declare_winner(&e);
	ft_exit(&e, 0);
	// ft_debug(e);
	// t_cursor *cursor;
	// cursor = (t_cursor*)malloc(sizeof(*cursor) * 10);
	// ft_tests_st(e, &cursor[0]);
	return(0);
}
