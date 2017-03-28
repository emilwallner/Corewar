/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:02:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/28 16:38:58 by mhaziza          ###   ########.fr       */
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

int get_short(t_env *e, t_cursor *cursor, int r)
{
	unsigned short	ret;

	ret = ((ZMASK(e->a[MODA(r)].hex) << 8) | ZMASK(e->a[MODA(r + 1)].hex));
	return ((short)ret);
}

void	ft_st(t_env *e, t_cursor *cursor)
{
	char	acb;
	int		p1;
	short	p2;
	int		i;
	int		size;
	int		v;

	acb = e->a[cursor->index + 1].hex;
	p1 = e->a[cursor->index + 2].hex;
	p2 = 0;
// printf("p1 %i reg[p1] %x acb %x\n", p1, cursor->reg[p1], acb);
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
		p2 = (get_short(e, cursor, 3)) & 0xffff;
		// printf("p2 %i - %#x \n", p2, p2);
		p2 = p2 < 0 && p2 > -IDX_MOD ? p2 : MODX(p2);
		// printf("p2 %i - %#x \n", p2, p2);
		int byte = MODA(get_bytes(e, cursor, p2));
		byte = byte < 0 ? byte + MEM_SIZE : byte;
		// printf("byte %i\n", byte);
		i = -1;
		while (++i < 4)
		{
			v = cursor->index + byte + i;
			e->a[MODA((v))].hex = (cursor->reg[p1 - 1] >> (8 * (3 - i))) & 0xff;
			e->a[MODA((v))].color = cursor->color - 6;
			e->a[MODA((v))].prevcolor = cursor->color - 6;
			e->a[MODA((v))].new_color_count = 50;
			// printf("v %i\n", MODA((v)));
			// printf("reg[1] %x\n",(cursor->reg[p1 - 1] >> (8 * (3 - i))) & 0xff);
		}
		ft_update_cursor(e, cursor, 5);
	}
}
