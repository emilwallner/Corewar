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

void ft_store_and_check_operation(t_env *e, t_cursor *cursor)
{
	if(ft_check_args(*e, *cursor))
	{
		//ft_copy_command(e);
		ft_ld(e, cursor);
		cursor->cycle = e->op_tab[e->a[cursor->index].hex].cycles;
		cursor->running = 1;
		//cursor->comnd_len = calc_len_of_op(cursor);
		cursor->comnd_len = 5;

	}
	else
		ft_update_cursor(e, cursor, 1);
}
