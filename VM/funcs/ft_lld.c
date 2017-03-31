/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:07:21 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/31 10:37:08 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions:
** Means long-load. Same as ld, but without % IDX_MOD.
** No % IDX_MOD
** Modify the carry
*/

static void	ft_dr(t_env *e, t_cursor *cursor, int opc_ind)
{
	int					value;

	value = get_bytes(e, cursor, opc_ind + 2);
	if (e->a[MODA(opc_ind + 2 + 4)].hex - 1 >= 1 &&
	e->a[MODA(opc_ind + 2 + 4)].hex - 1 <= REG_NUMBER)
	{
		cursor->reg[e->a[MODA(opc_ind + 2 + 4)].hex - 1] = value;
		if (value == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
	ft_update_cursor(e, cursor, 7);
}

static void	ft_ir(t_env *e, t_cursor *cursor, int opc_ind)
{
	unsigned short		r;
	int					value;

	r = ((ZMASK(e->a[MODA(opc_ind + 2)].hex) << 8) |
	ZMASK(e->a[MODA(opc_ind + 3)].hex));
	value = get_bytes(e, cursor, (short)r + opc_ind);
	if (e->a[MODA((opc_ind + 2 + 2))].hex - 1 >= 1 &&
	e->a[MODA(opc_ind + 2 + 2)].hex - 1 <= REG_NUMBER)
	{
		cursor->reg[e->a[MODA(opc_ind + 2 + 2)].hex - 1] = value;
		if (value == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
	ft_update_cursor(e, cursor, 5);
}

void		ft_lld(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			opc_ind;

	opc_ind = cursor->index;
	acb = e->a[MODA(opc_ind + 1)].hex;
	if (DR == ZMASK(acb))
		ft_dr(e, cursor, opc_ind);
	else if (IR == ZMASK(acb))
		ft_ir(e, cursor, opc_ind);
}
