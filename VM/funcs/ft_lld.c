/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:07:21 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/29 14:49:50 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
**
** Instructions:
** Means long-load. Same as ld, but without % IDX_MOD.
** No % IDX_MOD
** Modify the carry
**
*/


void	ft_lld(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			value;
	int			opc_ind;
	unsigned short		r;

	opc_ind = cursor->index;
	acb = e->a[MODA(opc_ind + 1)].hex;
	if (DR == ZMASK(acb))
	{
		value = get_bytes(e, cursor, opc_ind + 2);
		// printf("V = %i\n", value);
		if (e->a[MODA(opc_ind + 2 + 4)].hex - 1 >= 1 && e->a[MODA(opc_ind + 2 + 4)].hex - 1 <= REG_NUMBER)
		{
			cursor->reg[e->a[MODA(opc_ind + 2 + 4)].hex - 1] = value;
			if (value == 0)
				cursor->carry = 1;
			else
				cursor->carry = 0;
		}
		ft_update_cursor(e, cursor, 7);
	}
	else if (IR == ZMASK(acb))
	{
		r = ((ZMASK(e->a[MODA(opc_ind + 2)].hex) << 8) | ZMASK(e->a[MODA(opc_ind + 3)].hex));
		value = get_bytes(e, cursor, (short)r + opc_ind);
		if (e->a[MODA((opc_ind + 2 + 2))].hex - 1 >= 1 && e->a[MODA(opc_ind + 2 + 2)].hex - 1 <= REG_NUMBER)
		{
			cursor->reg[e->a[MODA(opc_ind + 2 + 2)].hex - 1] = value;
			if (value == 0)
				cursor->carry = 1;
			else
				cursor->carry = 0;
		}
		ft_update_cursor(e, cursor, 5);
	}
}
