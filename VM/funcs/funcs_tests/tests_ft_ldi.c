/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_ldi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:31:16 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/27 21:32:08 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/vm.h"

void	ft_debug_ldi(t_env e, t_cursor *cursor)
{
	int i = 0;
	// test RRR
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0x54;
	// e.a[2].hex = 0x01;
	// e.a[3].hex = 0x02;
	// e.a[4].hex = 0x03;
	// e.a[5].hex = 0x00;
	// e.a[6].hex = 0x0a;
	// test RDR
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0x64;
	// e.a[2].hex = 0x01;
	// e.a[3].hex = 0x00;
	// e.a[4].hex = 0x05;
	// e.a[5].hex = 0x03;
	// e.a[6].hex = 0x0a;

	// test DRR
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0x94;
	// e.a[2].hex = 0x00;
	// e.a[3].hex = 0x05;
	// e.a[4].hex = 0x01;
	// e.a[5].hex = 0x03;
	// e.a[6].hex = 0x0a;
	// test IRR
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0xd4;
	// e.a[2].hex = 0x00;
	// e.a[3].hex = 0x03;
	// e.a[4].hex = 0x01;
	// e.a[5].hex = 0x03;
	// e.a[6].hex = 0x05;
	// test IDR
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0xe4;
	// e.a[2].hex = 0x00;
	// e.a[3].hex = 0x04;
	// e.a[4].hex = 0x01;
	// e.a[5].hex = 0x2c;
	// e.a[6].hex = 0x03;
	// test DDR
	e.a[0].hex = 0x0b;
	e.a[1].hex = 0xa4;
	e.a[2].hex = 0x01;
	e.a[3].hex = 0x2c;
	e.a[4].hex = 0x00;
	e.a[5].hex = 0x05;
	e.a[6].hex = 0x03;
	e.a[7].hex = 0x05;
	e.a[8].hex = 0x02;
	e.a[9].hex = 0x01;
	e.a[10].hex = 0x00;
	e.a[11].hex = 0x00;
	e.a[12].hex = 0x00;
	e.a[13].hex = 0x05;

	printf("Data: \n");
	while (i < 9)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	cursor->reg[1] = 300;
	cursor->reg[2] = 0;
	cursor->reg[3] = 0;
	// cursor->index = 0;

	// printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %x\n", cursor->reg[1]);
	// printf("reg[2] %i\n", cursor->reg[2]);
	printf("BEFORE reg[3] %i\n", cursor->reg[3]);
	// printf("e.a[4].hex %x\ne.a[5].hex %x\n", ZMASK(e.a[3].hex), ZMASK(e.a[4].hex));

	// printf("carry is %i\n", cursor->carry);
	// printf("index is %i\n", cursor->index);

	ft_ldi(&e, cursor);
	printf("AFTER reg[3] %i\n", cursor->reg[3]);

	// printf("\n\nAFTER FUNCTION CALL\n\n");
	// printf("carry is %i \n", cursor->carry);
	// printf("index is %i\n", cursor->index);
}
