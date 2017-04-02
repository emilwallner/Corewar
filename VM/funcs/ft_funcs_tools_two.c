/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_tools_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:16:15 by nsabbah           #+#    #+#             */
/*   Updated: 2017/04/02 16:21:21 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_init_v(t_env *e, t_cursor *cursor, t_var *v)
{
	v->r1 = 0;
	v->r2 = 0;
	v->r3 = 0;
	v->ind = 0;
	v->acb = e->a[MODA(cursor->index + 1)].hex;
	v->carry = 0;
}

int		is_reg_valid(int i)
{
	return (i > 0 && i <= REG_NUMBER);
}

int		get_ind_sti(t_env *e, t_cursor *cursor, int i)
{
	unsigned short	r;
	int				byte;

	r = ((ZMASK(e->a[MODA(cursor->index + i)].hex) << 8) |
	ZMASK(e->a[MODA(cursor->index + i + 1)].hex));
	if (r > 32767 && MODX(r))
		r = MODX(r) - 512;
	else
		r = MODX(r);
	byte = MODX(get_bytes(e, cursor, cursor->index + r));
	return (byte);
}
