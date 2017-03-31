/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/30 20:00:24 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_check_if_an_operation(t_env *e, t_cursor *cursor)
{
	int i;

	i = e->a[cursor->index].hex & 0xFF;
	if (i > 0 && i < 17)
		return (1);
	else
		return (0);
}

void	ft_add_cycle(t_env *e, t_cursor *cursor)
{
	if (ft_check_if_an_operation(e, cursor))
	{
		cursor->cycle += e->op_tab[e->a[cursor->index].hex & 0xFF].cycles - 2;
		cursor->running = 1;
	}
	else
		ft_update_cursor(e, cursor, 1);
}
