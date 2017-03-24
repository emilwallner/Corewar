/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:02:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/24 19:21:32 by mhaziza          ###   ########.fr       */
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
#define ZMASK(c) (c & 0xff)

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
	printf("reg[p1] %x acb %x\n", cursor->reg[p1], acb);
	if (RR == ZMASK(acb))
	{
		printf("RR\n");
		p2 = e->a[cursor->index + 3].hex;
		cursor->reg[p2] = cursor->reg[p1];
		printf("reg[p2] %x (expected: ?)\n", cursor->reg[p2]);
	}
	else if (RI == ZMASK(acb))
	{
		printf("RI\n");
		p2 = (ZMASK(e->a[cursor->index + 3].hex) << 8) |
		ZMASK(e->a[cursor->index + 4].hex);
		printf("p2 AV mod %i\n", p2);
		p2 = MODX(p2);
		printf("p2 AP mod %i\n", p2);
		i = -1;
		while (++i < 4)
			e->a[MODA((cursor->index + p2 + i))].hex = cursor->reg[p1] >> (8 * (3 - i));
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2].hex);
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2 + 1].hex);
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2 + 2].hex);
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2 + 3].hex);
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2 + 4].hex);
	}
}
