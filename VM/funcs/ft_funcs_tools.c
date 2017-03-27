/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:36:36 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/27 19:31:27 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

int		ft_is_reg(int r1, int r2, int r3)
{
	if (r1 < 0 || r1 > REG_SIZE ||
			r2 < 0 || r2 > REG_SIZE ||
				r3 < 0 || r3 > REG_SIZE)
		return (0);
	return (1);
}

int get_dir(t_env *e, t_cursor *cursor, int i, int bytes)
{
	int r;

	if (bytes == 2)
		r = (ZMASK(e->a[cursor->index + i].hex) << 8) |
				ZMASK(e->a[cursor->index + i + 1].hex);
	else if (bytes == 4)
		r = (ZMASK(e->a[cursor->index + i].hex) << 24) |
				(ZMASK(e->a[cursor->index + i + 1].hex) << 16) |
					(ZMASK(e->a[cursor->index + i + 2].hex) << 8) |
						ZMASK(e->a[cursor->index + i + 3].hex);
	// printf(">DIR i %i r %i  value i %i i+1 %i\n", i, r, ZMASK(e->a[cursor->index + 5].hex), ZMASK(e->a[cursor->index + 6].hex));
	return (r);
}

int get_ind(t_env *e, t_cursor *cursor, int i)
{
	int r;

	r = (ZMASK(e->a[cursor->index + i].hex) << 8) |
	ZMASK(e->a[cursor->index + i + 1].hex);
	// printf(">IND i %i r %i  value i %i i+1 %i\n", i, r, ZMASK(e->a[cursor->index + 3].hex), ZMASK(e->a[cursor->index + 4].hex));

	return (ZMASK(e->a[r].hex<< 24) | ZMASK(e->a[r + 1].hex<< 16) |
			ZMASK(e->a[r + 2].hex<< 8) | ZMASK(e->a[r + 3].hex));
}

int get_reg(t_env *e, t_cursor *cursor, int i)
{
	int r;

	r = ZMASK(e->a[cursor->index + i].hex);
	return (cursor->reg[r]);
}
