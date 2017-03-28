/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 11:29:33 by nsabbah          ###   ########.fr       */
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
	int			ind;
	char		acb;
	int			value;

	opc_ind = cursor->index;
	acb = e->a[MODA(opc_ind + 1)].hex;
	if (ZMASK(acb) == RRR)
	{
		r1 = e->a[MODA(opc_ind + 2)].hex;
		r2 = e->a[MODA(opc_ind + 3)].hex;
		r3 = e->a[MODA(opc_ind + 4)].hex;
		if (ft_is_reg(r1, r2, r3))
		{
			cursor->reg[r3 - 1] = cursor->reg[r1 - 1] | cursor->reg[r2 - 1];
			cursor->carry = 1;
		}
		cursor->index += 5;
	}
	else if (ZMASK(acb) == RDR)
	{
		r1 = e->a[MODA(opc_ind + 2)].hex;
		r2 = e->a[MODA(opc_ind + 7)].hex;
		if (ft_is_reg(r1, r2, r2))
			cursor->reg[r2] = cursor->reg[r1 - 1] & get_dir(e, cursor, 3, 4);
		cursor->index += 8;
	}
	else if (ZMASK(acb) == RIR)
	{
		r1 = e->a[MODA(opc_ind + 2)].hex;
		r2 = e->a[MODA(opc_ind + 5)].hex;
		if (ft_is_reg(r1, r2, r2))
		{
			cursor->reg[r2] = cursor->reg[r1 - 1] & get_ind(e, cursor, 3);
			cursor->carry = 1;
		}
			cursor->index += 6;
	}
	else if (ZMASK(acb) == IRR)
	{
		r1 = e->a[MODA(opc_ind + 4)].hex;
		r2 = e->a[MODA(opc_ind + 5)].hex;
		if (ft_is_reg(r1, r2, r2))
		{
			cursor->reg[r2] = cursor->reg[r1 - 1] & get_ind(e, cursor, 2);
			cursor->carry = 1;
		}
			cursor->index += 6;
	}
	else if (ZMASK(acb) == DRR)
	{
		r1 = e->a[MODA(opc_ind + 6)].hex;
		r2 = e->a[MODA(opc_ind + 7)].hex;
		if (ft_is_reg(r1, r2, r2))
		{
			cursor->reg[r2] = cursor->reg[r1 - 1] & get_dir(e, cursor, 2, 4);
			cursor->carry = 1;
		}
			cursor->index += 8;
	}
	else if (ZMASK(acb) == DDR)
	{
		r1 = e->a[MODA(opc_ind + 10)].hex;
		if (ft_is_reg(r1, r1, r1))
		{
			cursor->reg[r1 - 1] = get_dir(e, cursor, 2, 4) &
				get_dir(e, cursor, 6, 4);
			cursor->carry = 1;
		}
			cursor->index += 11;
	}
	else if (ZMASK(acb) == DIR)
	{
		r1 = e->a[MODA(opc_ind + 8)].hex;
		if (ft_is_reg(r1, r1, r1))
		{
			cursor->reg[r1 - 1] = get_dir(e, cursor, 2, 4) &
				get_ind(e, cursor, 6);
			cursor->carry = 1;
		}
			cursor->index += 9;
	}
	else if (ZMASK(acb) == IIR)
	{
		r1 = e->a[MODA(opc_ind + 6)].hex;
		if (ft_is_reg(r1, r1, r1))
		{
			cursor->reg[r1 - 1] = get_ind(e, cursor, 2) &
				get_ind(e, cursor, 4);
			cursor->carry = 1;
		}
			cursor->index += 7;
	}
	else if (ZMASK(acb) == IDR)
	{
		r1 = e->a[MODA(opc_ind + 8)].hex;
		if (ft_is_reg(r1, r1, r1))
		{
			cursor->reg[r1 - 1] = get_ind(e, cursor, 2) &
				get_dir(e, cursor, 4, 4);
			cursor->carry = 1;
		}
			cursor->index += 9;
	}
}
