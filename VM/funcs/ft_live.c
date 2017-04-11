/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:07:21 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/30 19:51:10 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

int		ft_live_match(t_env *e, int player_id)
{
	int i;

	i = 0;
	while (i < e->player_amount)
	{
		if (e->player[i].nbr == player_id)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_live(t_env *e, t_cursor *cursor)
{
	int player_id;
	int player_pos;

	player_id = get_dir(e, cursor, 1, 4);
	player_pos = ft_live_match(e, player_id);
	if (player_pos > -1)
	{
		e->lives += 1;
		cursor->life = 1;
		e->player[player_pos].live += 1;
		e->winner = player_pos;
		ft_update_cursor(e, cursor, 5);
	}
	else
		ft_update_cursor(e, cursor, 5);
}
