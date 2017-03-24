/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 16:16:51 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions:
** Take a random argument and a registry. Load the value of the first argument
** in the registry. Its opcode is 10 in binary and it will change the carry.
**
** Should the IND part should be % MEM_SIZE or similar?
*/

void	ft_ld(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			value;
	int			opc_ind;
	short int	ind_value;

	opc_ind = cursor->index;
	acb = e->a[opc_ind + 1].hex;
	if (((acb) >> 6) == DIR_CODE)
	{
		value = ft_cp_int(opc_ind + 2, *e);
		cursor->reg[e->a[opc_ind + 2 + 4].hex] = value;
		cursor->index += 7;
	}
	else
	{
		ind_value = ((e->a[opc_ind + 2].hex & 0xFF) << 8)
									+ (e->a[opc_ind + 3].hex & 0xFF);
		value = ft_cp_int(opc_ind + ind_value, *e);
		cursor->reg[e->a[opc_ind + 2 + 2].hex] = value;
		cursor->index += 5;
	}
	cursor->carry = 1;
}
