/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:02:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/28 13:46:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions:
** Take a registry and a registry or an indirect and store the value of the
** registry toward a second argument. Its opcode is 0x03. For example, st r1, 42
** store the value of r1 at the address (PC + (42 % IDX_MOD))
*/

#define RR 0x50
#define RI 0x70
// #define ZMASK(c) (c & 0xff)

void	ft_st(t_env *e, t_cursor *cursor)
{
	char	acb;
	int		p1;
	int		p2;
	int		i;
	int		size;

	acb = e->a[cursor->index + 1].hex;
	p1 = e->a[cursor->index + 2].hex;
	p2 = 0;
//	printf("reg[p1] %x acb %x\n", cursor->reg[p1], acb);
	if (RR == ZMASK(acb))
	{
	//	printf("RR\n");
		p2 = e->a[cursor->index + 3].hex;
		cursor->reg[p2 - 1] = cursor->reg[p1 - 1];
		ft_update_cursor(e, cursor, 4);
	//	printf("reg[p2] %x (expected: ?)\n", cursor->reg[p2]);
	}
	else if (RI == ZMASK(acb))
	{
	//	printf("RI\n");
		p2 = get_bytes(e, cursor, 4);
		p2 = p2 < 0 && p2 > -512 ? p2 : MODX(p2);
		i = -1;
		while (++i < 4)
			e->a[MODA((cursor->index + p2 + i))].hex = cursor->reg[p1 - 1] >> (8 * (3 - i));
		ft_update_cursor(e, cursor, 7);
	}
}
