/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/23 17:31:51 by nsabbah          ###   ########.fr       */
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
	char		acb;
	int		i;
	int		value;
	int		ocp_ind;

	printf("HELLO\n");
	i = 4;
	ocp_ind = cursor->index;
	// ocp_ind = copied_code;
	acb = e->a[ocp_ind + 1].hex;
	// acb =  0xFF & copied_code[1];
	if ((acb >> 6) == DIR_CODE)
	{
		printf("DIR\n");
		// ocp_ind += 2;
		// value = ft_cp_int(ocp_ind, *e);
		// cursor->reg[e->a[ocp_ind + 2 + 4].hex] = value;
		// cursor->reg[copied_code[2 + 4]] = value;
		// cursor->index += 7;
	}
	else
	{
		printf("IND\n");
		// ocp_ind += e->a[ocp_ind + e->a[ocp_ind + 3].hex].hex;
		// value = ft_cp_int(ocp_ind, *e);
		// cursor->reg[e->a[ocp_ind + 2 + 2].hex] = value;
		// cursor->reg[copied_code[2 + 2]] = value;
		// cursor->index += 5;
		// ocp_ind += (*(copied_code + 3) % IDX_MOD);
	}
	cursor->carry = 1;
}
