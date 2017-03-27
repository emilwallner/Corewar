/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/27 16:57:13 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions: Same as add, but with the opcode est 0b101 (5 in decimal)
** and uses a substraction
*/

void	ft_sub(t_env *e, t_cursor *cursor)
{
	int			opc_ind;
	int			r1;
	int			r2;
	int			r3;

	printf("HELLO\n");
	opc_ind = cursor->index;
	r1 = e->a[MODA(opc_ind + 2)].hex;
	r2 = e->a[MODA(opc_ind + 3)].hex;
	r3 = e->a[MODA(opc_ind + 4)].hex;
	if (!ft_is_reg(r1, r2, r3))
	{
		cursor->index += 5;
		return ;
	}
	cursor->reg[r3] = cursor->reg[r1] - cursor->reg[r2];
	cursor->index += 5;
	cursor->carry = 1;
}
