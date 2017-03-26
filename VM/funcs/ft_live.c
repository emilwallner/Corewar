/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:07:21 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 17:07:17 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_live(t_env *e, t_cursor *cursor)
{
	char player_id;
	(void)cursor;
	e->lives += 1;
	player_id = e->a[cursor->index + 4].hex;
	if(player_id != 0 && player_id < e->player_amount)
	{
		e->player[player_id].live += 1;
		e->winner = player_id;
		ft_update_cursor(e, cursor, 5);	
	}
	else
		ft_update_cursor(e, cursor, 1);
}
