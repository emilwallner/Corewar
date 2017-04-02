/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/04/02 15:32:25 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_aff(t_env *e, t_cursor *cursor)
{
	int		index_extra;
	int		r;
	int		acb;

	r = ZMASK(e->a[MODA(cursor->index + 2)].hex);
	acb = ZMASK(e->a[MODA(cursor->index + 1)].hex);
	if (r < 0 || r > 15 || acb != 64)
		ft_update_cursor(e, cursor, 3);
	else
	{
		index_extra = get_reg(e, cursor, 2) % 256;
		if (e->bonus)
			printw("Aff: %C\n", index_extra);
		else
			ft_printf("Aff: %C\n", index_extra);
		ft_update_cursor(e, cursor, 3);
	}
}
