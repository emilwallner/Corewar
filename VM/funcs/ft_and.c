/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/27 18:38:21 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions: Apply an & (bit-to-bit AND) over the first two arguments
** and store the result in a registry, which is the third argument.
** Opcode 0x06. Modifies the carry.
** T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG
*/

void	ft_and(t_env *e, t_cursor *cursor)
{
	int			opc_ind;
	int			r1;
	int			r2;
	int			r3;
	char		acb;
	int			value;

	opc_ind = cursor->index;
	acb = e->a[MODA(opc_ind + 1)].hex;
	if ((acb & 0xFF) == RRR)
	{
		r1 = e->a[MODA(opc_ind + 2)].hex;
		r2 = e->a[MODA(opc_ind + 3)].hex;
		r3 = e->a[MODA(opc_ind + 4)].hex;
		if (ft_is_reg(r1, r2, r3))
			cursor->reg[r3] = cursor->reg[r1] | cursor->reg[r2];
		cursor->index += 5;
	}
}
