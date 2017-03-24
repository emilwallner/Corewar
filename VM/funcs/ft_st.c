/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:02:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/24 18:36:48 by mhaziza          ###   ########.fr       */
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

int		nb_bytes(int value)
{
	int tmp;
	int k;

	k = 1;
	tmp = value;
	while ((value = value / 256))
		k++;
	printf("k nb_bytes %i\n", k);
	return (k);
}

void	ft_st(t_env *e, t_cursor *cursor)
{
	char	acb;
	int		p1;
	int		p2;
	int		i;
	int		size;

	acb = e->a[cursor->index + 1].hex;
	p1 = e->a[cursor->index + 2].hex;
	printf("acb in hex %x\n", acb & 0xFF);
	if ((char)RR == acb)
	{
		printf("reg[2] %i (expected: ?)\n", cursor->reg[1]);
		p2 = e->a[cursor->index + 3].hex;
		cursor->reg[p2] = cursor->reg[p1];
		printf("reg[2] %i (expected: ?)\n", cursor->reg[1]);
	}
	else
	{
		p2 = (ZMASK(e->a[cursor->index + 3].hex) << 8) | ZMASK(e->a[cursor->index + 3].hex);
		p2 = MODX(p2);
		i = 0;
		size = nb_bytes(cursor->reg[p1]);
		while (4 - size)
		{
			e->a[MODA((cursor->index + p2 + i))].hex = 0;
			size++;
			i++;
		}
		size = nb_bytes(cursor->reg[p1]);
		while (size > 1)
		{
			e->a[MODA((cursor->index + p2 + i))].hex = cursor->reg[p1] / 256;
			size--;
			i++;
		}
		e->a[MODA((cursor->index + p2 + i))].hex = cursor->reg[p1] % 256;
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2].hex);
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2 + 1].hex);
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2 + 2].hex);
		printf("p2 %i arene[p2] %x \n", p2, e->a[cursor->index + p2 + 3].hex);
	}
	printf("RI\n");
}
