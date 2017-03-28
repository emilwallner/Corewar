/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:00:59 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 14:01:04 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/vm.h"

void	ft_tests_or(t_env e, t_cursor *cursor)
{
	int i = 0;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = RRR;

	e.a[2].hex = 0x02;

	e.a[3].hex = 0x03;

	e.a[4].hex = 0x04;

	printf(CYAN "INFO : RRR type\n\n" RESET);
	printf("Data: \n");
	while (i < 4)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[1] = 0b10110100 & 0xFF;
	cursor->reg[2] = 0b11101001 & 0xFF;
	cursor->reg[3] = 8;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("reg[2] %i\n", cursor->reg[2]);
	printf("reg[3] %i\n", cursor->reg[3]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[3] - (cursor->reg[1] | cursor->reg[2]) || cursor->carry - 1 || cursor->index - 5)
		printf(RED);
	printf("reg[3] %i (expected: %i)\n", cursor->reg[3], cursor->reg[1] | cursor->reg[2]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 5)\n", cursor->index);
	printf(RESET);
}

void	ft_tests_or1(t_env e, t_cursor *cursor)
{
	int i = 0;
	int direct;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = RDR;

	e.a[2].hex = 0x02;

	e.a[3].hex = 0x13;
	e.a[4].hex = 0x32;
	e.a[5].hex = 0x83;
	e.a[6].hex = 0x11;

	e.a[7].hex = 0x03;

	printf(CYAN "\nINFO : RDR (D 4 bytes)\n\n" RESET);
	printf("Data: \n");
	while (i < 8)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[1] = 0x10229409;
	cursor->reg[2] = 2;
	cursor->index = 0;
	direct = get_dir(&e, cursor, 3, 4);
	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("direct is %#x\n", direct);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[2] - (direct | cursor->reg[1]) || cursor->carry - 1 || cursor->index - 8)
		printf(RED);
	printf("reg[2] %i (expected: %i)\n", cursor->reg[2], direct | cursor->reg[1]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 8)\n", cursor->index);
	printf(RESET);
}

void	ft_tests_or2(t_env e, t_cursor *cursor)
{
	int i = 0;
	int ind;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = RIR;

	e.a[2].hex = 0x02;

	e.a[3].hex = 0x00;
	e.a[4].hex = 0x04;

	e.a[5].hex = 0x03;

	e.a[6].hex = 0x00;
	e.a[7].hex = 0x10;
	e.a[8].hex = 0x43;
	e.a[9].hex = 0x11;
	e.a[10].hex = 0x03;
	e.a[11].hex = 0x03;
	e.a[12].hex = 0x43;
	e.a[13].hex = 0x11;
	e.a[14].hex = 0x03;

	printf(CYAN "\nINFO : RIR (D 4 bytes)\n\n" RESET);
	printf("Data: \n");
	while (i < 15)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[1] = 0x10229409;
	cursor->index = 0;
	ind = get_ind(&e, cursor, 3);
	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("ind is %#x\n", ind);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[2] - (ind | cursor->reg[1]) || cursor->carry - 1 || cursor->index - 6)
		printf(RED);
	printf("reg[2] %i (expected: %i)\n", cursor->reg[2], ind | cursor->reg[1]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 6)\n", cursor->index);
	printf(RESET);
}

void	ft_tests_or3(t_env e, t_cursor *cursor)
{
	int i = 0;
	int ind;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = IRR;

	e.a[2].hex = 0x00;
	e.a[3].hex = 0x07;

	e.a[4].hex = 0x02;

	e.a[5].hex = 0x03;

	e.a[6].hex = 0x00;
	e.a[7].hex = 0x10;
	e.a[8].hex = 0x43;
	e.a[9].hex = 0x11;
	e.a[10].hex = 0x03;
	e.a[11].hex = 0x03;
	e.a[12].hex = 0x43;
	e.a[13].hex = 0x11;
	e.a[14].hex = 0x03;

	printf(CYAN "\nINFO : IRR\n\n" RESET);
	printf("Data: \n");
	while (i < 15)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[1] = 0x20ff203;
	cursor->index = 0;
	ind = get_ind(&e, cursor, 2);
	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("ind is %#x\n", ind);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[2] - (ind | cursor->reg[1]) || cursor->carry - 1 || cursor->index - 6)
		printf(RED);
	printf("reg[2] %i (expected: %i)\n", cursor->reg[2], ind | cursor->reg[1]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 6)\n", cursor->index);
	printf(RESET);
}

void	ft_tests_or4(t_env e, t_cursor *cursor)
{
	int i = 0;
	int ind;
	int direct;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = DRR;

	e.a[2].hex = 0x00;
	e.a[3].hex = 0x02;
	e.a[4].hex = 0x50;
	e.a[5].hex = 0x03;

	e.a[6].hex = 0x02;

	e.a[7].hex = 0x03;

	printf(CYAN "\nINFO : DRR\n\n" RESET);
	printf("Data: \n");
	while (i < 8)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[1] = 0x20ff203;
	cursor->index = 0;
	direct = get_dir(&e, cursor, 2, 4);
	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("dir is %#x\n", direct);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[2] - (direct | cursor->reg[1]) || cursor->carry - 1 || cursor->index - 8)
		printf(RED);
	printf("reg[2] %i (expected: %i)\n", cursor->reg[2], direct | cursor->reg[1]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 8)\n", cursor->index);
	printf(RESET);
}

void	ft_tests_or5(t_env e, t_cursor *cursor)
{
	int i = 0;
	int ind;
	int direct1;
	int direct2;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = DDR;

	e.a[2].hex = 0xdd;
	e.a[3].hex = 0x02;
	e.a[4].hex = 0x02;
	e.a[5].hex = 0x99;

	e.a[6].hex = 0xFF;
	e.a[7].hex = 0xFA;
	e.a[8].hex = 0x00;
	e.a[9].hex = 0xFC;

	e.a[10].hex = 0x03;

	e.a[11].hex = 0x03;
	e.a[12].hex = 0x43;
	e.a[13].hex = 0x11;
	e.a[14].hex = 0x03;

	printf(CYAN "\nINFO : DDR\n\n" RESET);
	printf("Data: \n");
	while (i < 15)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[1] = 0x2ff0203;
	cursor->index = 0;
	direct1 = get_dir(&e, cursor, 2, 4);
	direct2 = get_dir(&e, cursor, 6, 4);
	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("direct1 is %#x\n", direct1);
	printf("direct2 is %#x\n", direct2);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[2] - (direct1 | direct2) || cursor->carry - 1 || cursor->index - 11)
		printf(RED);
	printf("reg[2] %i (expected: %i)\n", cursor->reg[2], direct1 | direct2);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 11)\n", cursor->index);
	printf(RESET);
}

void	ft_tests_or6(t_env e, t_cursor *cursor)
{
	int i = 0;
	int ind;
	int direct1;
	int direct2;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = DIR;

	e.a[2].hex = 0x00;
	e.a[3].hex = 0x02;
	e.a[4].hex = 0xf2;
	e.a[5].hex = 0x99;

	e.a[6].hex = 0x00;
	e.a[7].hex = 0x07;

	e.a[8].hex = 0x03;

	e.a[9].hex = 0xFC;

	e.a[10].hex = 0x03;

	e.a[11].hex = 0x03;
	e.a[12].hex = 0x43;
	e.a[13].hex = 0x11;
	e.a[14].hex = 0x03;

	printf(CYAN "\nINFO : DIR\n\n" RESET);
	printf("Data: \n");
	while (i < 15)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	// cursor->reg[1] = 0x20203;
	cursor->index = 0;
	direct1 = get_dir(&e, cursor, 2, 4);
	ind = get_ind(&e, cursor, 6);
	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("direct1 is %#x\n", direct1);
	printf("ind is %#x\n", ind);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[2] - (direct1 | ind) || cursor->carry - 1 || cursor->index - 9)
		printf(RED);
	printf("reg[2] %i (expected: %i)\n", cursor->reg[2], direct1 | ind);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 9)\n", cursor->index);
	printf(RESET);
}

void	ft_tests_or7(t_env e, t_cursor *cursor)
{
	int i = 0;
	int ind1;
	int ind2;
	int direct1;
	int direct2;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = IIR;

	e.a[2].hex = 0x00;
	e.a[3].hex = 0x05;

	e.a[4].hex = 0x00;
	e.a[5].hex = 0x08;

	e.a[6].hex = 0x03;

	e.a[7].hex = 0x07;
	e.a[8].hex = 0x03;
	e.a[9].hex = 0xFC;
	e.a[10].hex = 0x03;
	e.a[11].hex = 0x03;
	e.a[12].hex = 0x43;
	e.a[13].hex = 0x11;
	e.a[14].hex = 0x03;

	printf(CYAN "\nINFO : IIR\n\n" RESET);
	printf("Data: \n");
	while (i < 15)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	// cursor->reg[1] = 0x20203;
	cursor->index = 0;
	// direct1 = get_dir(&e, cursor, 2, 4);
	ind1 = get_ind(&e, cursor, 2);
	ind2 = get_ind(&e, cursor, 4);
	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	// printf("direct1 is %#x\n", direct1);
	printf("ind is %#x\n", ind1);
	printf("ind is %#x\n", ind2);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[2] - (ind1 | ind2) || cursor->carry - 1 || cursor->index - 7)
		printf(RED);
	printf("reg[2] %i (expected: %i)\n", cursor->reg[2], ind1 | ind2);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 7)\n", cursor->index);
	printf(RESET);
}

void	ft_tests_or8(t_env e, t_cursor *cursor)
{
	int i = 0;
	int ind;
	int direct;
	// Building the fake copied code:
	e.a[0].hex = 0x06;
	e.a[1].hex = IDR;

	e.a[2].hex = 0x00;
	e.a[3].hex = 0x02;

	e.a[4].hex = 0x02;
	e.a[5].hex = 0x99;
	e.a[6].hex = 0x00;
	e.a[7].hex = 0x07;

	e.a[8].hex = 0x03;

	e.a[9].hex = 0xFC;

	e.a[10].hex = 0x03;

	e.a[11].hex = 0x03;
	e.a[12].hex = 0x43;
	e.a[13].hex = 0x11;
	e.a[14].hex = 0x03;

	printf(CYAN "\nINFO : IDR\n\n" RESET);
	printf("Data: \n");
	while (i < 15)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	// cursor->reg[1] = 0x20203;
	cursor->index = 0;
	direct = get_dir(&e, cursor, 4, 4);
	ind = get_ind(&e, cursor, 2);
	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("direct is %#x\n", direct);
	printf("ind is %#x\n", ind);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_or(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	if (cursor->reg[2] - (direct | ind) || cursor->carry - 1 || cursor->index - 9)
		printf(RED);
	printf("reg[2] %i (expected: %i)\n", cursor->reg[2], direct | ind);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 9)\n", cursor->index);
	printf(RESET);
}
