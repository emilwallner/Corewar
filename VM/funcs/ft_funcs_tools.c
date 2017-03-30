/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:16:15 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/30 15:33:20 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Take the index of reg (between 0 and 15 for example if REG_NUMBER = 16)
*/

int		ft_is_reg(int r1, int r2, int r3)
{
	if (r1 < 0 || r1 >= REG_NUMBER ||
			r2 < 0 || r2 >= REG_NUMBER ||
				r3 < 0 || r3 >= REG_NUMBER)
		return (0);
	return (1);
}

int get_bytes(t_env *e, t_cursor *cursor, int r)
{
	unsigned int	ret;

	ret = (ZMASK(e->a[MODA(r)].hex) << 24) | (ZMASK(e->a[MODA((r + 1))].hex) << 16)
	| (ZMASK(e->a[MODA((r + 2))].hex) << 8) | ZMASK(e->a[MODA((r + 3))].hex);
	return ((int)ret);
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
	if (bytes == 2)
		return ((short)r);
	return ((int)r);
}

int get_ind(t_env *e, t_cursor *cursor, int i)
{
	unsigned short	r;

	r = ((ZMASK(e->a[MODA(i)].hex) << 8) | ZMASK(e->a[MODA(i + 1)].hex));
	return (MODA(get_bytes(e, cursor, (short)r)));
}

int get_reg(t_env *e, t_cursor *cursor, int i)
{
	int r;

	r = ZMASK(e->a[MODA(cursor->index + i)].hex);
	if (r > 0 && r <= REG_NUMBER)
		return (cursor->reg[r - 1]);
	return (0);
}
