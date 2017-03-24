/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 17:25:40 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions:
**
** ldi, ldi, as per the name, does not imply to go swimming in chestnut cream,
** even if its code is 0x0a. Instead, it will use 2 indexes and 1 registry,
** adding the first two, treating that like an address, reading a value of a
** registry’s size and putting it on the third.
**
*/

void	ft_ldi(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			value;
	int			opc_ind;
	short int	ind_value;

	opc_ind = cursor->index;
	acb = e->a[MODA(opc_ind + 1)].hex;
	if (((acb & 0xFF) >> 6) == DIR_CODE)
	{
		value = ft_cp_int(MODA(opc_ind + 2), *e);
		cursor->reg[e->a[MODA(opc_ind + 2 + 4)].hex] = value;
		cursor->index += 7;
	}
	else
	{
		ind_value = ((e->a[MODA(opc_ind + 2)].hex & 0xFF) << 8)
									+ (e->a[MODA(opc_ind + 3)].hex & 0xFF);
		ind_value = MODX(ind_value) & 0xFFFF;
		value = ft_cp_int(MODA(opc_ind + ind_value), *e);
		cursor->reg[e->a[MODA(opc_ind + 2 + 2)].hex] = value;
		cursor->index += 5;
	}
	cursor->carry = 1;
}
