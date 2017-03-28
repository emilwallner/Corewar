/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:16:15 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 10:11:12 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

int		ft_is_reg(int r1, int r2, int r3)
{
	if (r1 < 0 || r1 > REG_NUMBER ||
			r2 < 0 || r2 > REG_NUMBER ||
				r3 < 0 || r3 > REG_NUMBER)
		return (0);
	return (1);
}

int get_bytes(t_env *e, t_cursor *cursor, int r)
{
	return (ZMASK(e->a[MODA(r)].hex << 24) | ZMASK(e->a[MODA(r + 1)].hex << 16)
	| ZMASK(e->a[MODA(r + 2)].hex << 8) | ZMASK(e->a[MODA(r + 3)].hex));
}

int get_dir(t_env *e, t_cursor *cursor, int i, int bytes)
{
	int r;

	if (bytes == 2)
		r = (ZMASK(e->a[MODA(cursor->index + i)].hex) << 8) |
				ZMASK(e->a[MODA(cursor->index + i + 1)].hex);
	else if (bytes == 4)
		r = (ZMASK(e->a[MODA(cursor->index + i)].hex) << 24) |
				(ZMASK(e->a[MODA(cursor->index + i + 1)].hex) << 16) |
					(ZMASK(e->a[MODA(cursor->index + i + 2)].hex) << 8) |
						ZMASK(e->a[MODA(cursor->index + i + 3)].hex);

	return (r);
}

int get_ind(t_env *e, t_cursor *cursor, int i)
{
	int r;

	r = (ZMASK(e->a[MODA(cursor->index + i)].hex) << 8) |
	ZMASK(e->a[MODA(cursor->index + i + 1)].hex);
	return (get_bytes(e, cursor, r));
}

int get_reg(t_env *e, t_cursor *cursor, int i)
{
	int r;

	r = ZMASK(e->a[MODA(cursor->index + i)].hex);
	if (r > 0 && r <= REG_NUMBER)
		return (cursor->reg[r - 1]);
	return (0);
}
