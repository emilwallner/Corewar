/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 15:33:35 by nsabbah          ###   ########.fr       */
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

int		ft_cp_int(int int_start, t_env e)
{
	int i;
	int value;

	i = 4;
	value = 0;
	while (--i >= 0)
		value += e.a[int_start + (3 - i)].hex << (i * 8);
	return (value);
}

void	ft_ld(t_env *e, t_cursor *cursor)
{
	char	acb;
	int		i;
	int		value;
	int		ocp_ind;


	i = 4;
	ocp_ind = cursor->index;
	acb = e->a[ocp_ind + 1].hex;
	//printf("acb in hex %x\n", acb & 0xFF);
	if (((acb & 0xFF) >> 6) == DIR_CODE)
	{
		//printf("\nDIR\n");
		value = ft_cp_int(ocp_ind + 2, *e);
		// printf("value is %i\n", value);
		// printf("ocp_ind + 2 + 4 is %i\n", ocp_ind + 2 + 4);
		cursor->reg[e->a[ocp_ind + 2 + 4].hex] = value;
		// printf("cursor->reg[2] value is %i\n", cursor->reg[2]);
		cursor->index += 7;
	}
	else
	{
		//printf("\nIND\n");
		value = ft_cp_int(ocp_ind + e->a[ocp_ind + e->a[ocp_ind + 3].hex].hex, *e);
		//printf("value is %i\n", value);
	//	printf("ocp_ind + 2 + 4 is %i\n", ocp_ind + 2 + 4);
		cursor->reg[e->a[ocp_ind + 2 + 2].hex] = value;
		//printf("cursor->reg[2] value is %i\n", cursor->reg[2]);
		// cursor->reg[copied_code[2 + 2]] = value;
		cursor->index += 5;
		// ocp_ind += (*(copied_code + 3) % IDX_MOD);
	}
	cursor->carry = 1;
}
