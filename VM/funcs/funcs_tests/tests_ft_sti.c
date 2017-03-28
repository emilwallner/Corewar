/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_sti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:31:16 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 10:41:44 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/vm.h"

void	ft_debug_sti(t_env e, t_cursor *cursor)
{
	int i = 0;
	// test RRR
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0x54;
	// e.a[2].hex = 0x01;
	// e.a[3].hex = 0x02;
	// e.a[4].hex = 0x03;
	// test RRD
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0x58;
	// e.a[2].hex = 0x01;
	// e.a[3].hex = 0x02;
	// e.a[4].hex = 0x00;
	// e.a[5].hex = 0x05;
	// test RDR
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0x64;
	// e.a[2].hex = 0x01;
	// e.a[3].hex = 0x00;
	// e.a[4].hex = 0x05;
	// e.a[5].hex = 0x02;
	// test RIR
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0x74;
	// e.a[2].hex = 0x01;
	// e.a[3].hex = 0x00;
	// e.a[4].hex = 0x0a;
	// e.a[5].hex = 0x02;
	// test RID
	e.a[0].hex = 0x0b;
	e.a[1].hex = 0x78;
	e.a[2].hex = 0x01;
	e.a[3].hex = 0x00;
	e.a[4].hex = 0x0a;
	e.a[5].hex = 0x00;
	e.a[6].hex = 0x0a;
	// test RDD
	// e.a[0].hex = 0x0b;
	// e.a[1].hex = 0b01101000;
	// e.a[2].hex = 0x01;
	// e.a[3].hex = 0x00;
	// e.a[4].hex = 0x00;
	// e.a[5].hex = 0x00;
	// e.a[6].hex = 0x0a;
	e.a[7].hex = 0x0a;
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
	cursor->reg[2] = 5;
	cursor->reg[3] = 10;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %x\n", cursor->reg[1]);
	printf("reg[2] %i\n", cursor->reg[2]);
	// printf("e.a[4].hex %x\ne.a[5].hex %x\n", ZMASK(e.a[3].hex), ZMASK(e.a[4].hex));

	// printf("carry is %i\n", cursor->carry);
	// printf("index is %i\n", cursor->index);

	ft_sti(&e, cursor);
	i = 0;
	while (i < 4)
	{
		printf("e.a[10 + i] %x \n", e.a[cursor->index + 9 + i].hex);
		i++;
	}
	// printf("\n\nAFTER FUNCTION CALL\n\n");
	// printf("carry is %i \n", cursor->carry);
	// printf("index is %i\n", cursor->index);
}

// void	ft_debug_st2(t_env e, t_cursor *cursor)
// {
// 	// From the asm : 02 90 00 00 00 0a 02
// 	int i = 0;
// 	e.a[0].hex = 0x03;
// 	e.a[1].hex = 0x50;
// 	e.a[2].hex = 0x01;
// 	e.a[3].hex = 0x02;
// 	e.a[4].hex = 0x03;
// 	e.a[5].hex = 0x70;
// 	e.a[6].hex = 0x01;
// 	e.a[7].hex = 0x00;
// 	e.a[8].hex = 0x0a;
//
// 	printf(CYAN "\nINFO : Test with DIR (4 bytes), write value in R2\n\n" RESET);
// 	printf("Data: \n");
// 	while (i < 7)
// 	{
// 		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
// 		i++;
// 	}
// 	printf("\n");
// 	cursor->reg[2] = 8;
// 	cursor->index = 0;
//
// 	printf("\nBEFORE FUNCTION CALL\n\n");
//
// 	printf("reg[2] %i\n", cursor->reg[2]);
// 	printf("carry is %i\n", cursor->carry);
// 	printf("index is %i\n", cursor->index);
//
// 	ft_ld(&e, cursor);
//
// 	printf("\n\nAFTER FUNCTION CALL\n\n");
// 	printf("reg[2] %i (expected: 1012323)\n", cursor->reg[2]);
// 	printf("carry is %i (expected: 1)\n", cursor->carry);
// 	printf("index is %i\n", cursor->index);
// }
