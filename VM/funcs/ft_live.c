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
	int player_id;

	player_id = ABS(get_dir(e, cursor, 1, 4)) - 1;
	if(player_id > -1 && player_id < e->player_amount)
	{
		e->lives += 1;
		e->player[player_id].live += 1;
		e->winner = player_id + 1;
		ft_update_cursor(e, cursor, 5);
	}
	else
		ft_update_cursor(e, cursor, 1);
}
