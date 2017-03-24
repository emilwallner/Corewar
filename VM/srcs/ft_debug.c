/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:23:13 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 12:35:59 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** This part is to test each function while the core algo is being built
*/

void	ft_debug_ld(t_env e, t_cursor *cursor)
{
	int i = 0;
	// Building the fake copied code:
	e.a[0].hex = 0x02;
	e.a[1].hex = 0xd0;
	e.a[2].hex = 0x00;
	e.a[3].hex = 0x0a;
	e.a[4].hex = 0x02;
	e.a[5].hex = 0x02;
	e.a[6].hex = 0xd0;
	e.a[7].hex = 0x00;
	e.a[8].hex = 0x0a;
	e.a[9].hex = 0x02;
	e.a[10].hex = 0xff;
	e.a[11].hex = 0xff;
	e.a[12].hex = 0xff;
	e.a[13].hex = 0x01;

	printf(CYAN "INFO : Test with IND, write value of index + 10 in R2\n\n" RESET);
	printf("Data: \n");
	while (i < 14)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[2] = 8;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[2] %i\n", cursor->reg[2]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_ld(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	printf("reg[2] %i (expected: ?)\n", cursor->reg[2]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i\n", cursor->index);
}

void	ft_debug_ld2(t_env e, t_cursor *cursor)
{
	// From the asm : 02 90 00 00 00 0a 02
	int i = 0;
	e.a[0].hex = 0x02;
	e.a[1].hex = 0x90;
	e.a[2].hex = 0x00;
	e.a[3].hex = 0x0f;
	e.a[4].hex = 0x72;
	e.a[5].hex = 0x63;
	e.a[6].hex = 0x02;

	printf(CYAN "\nINFO : Test with DIR (4 bytes), write value in R2\n\n" RESET);
	printf("Data: \n");
	while (i < 7)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[2] = 8;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[2] %i\n", cursor->reg[2]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_ld(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	printf("reg[2] %i (expected: 1012323)\n", cursor->reg[2]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i\n", cursor->index);
}

void	ft_debug(t_env e)
{
	t_cursor *cursor;

	cursor = (t_cursor*)malloc(sizeof(*cursor) * 10);
	printf(RED "\n###### FUNCTION TEST : ft_ld.c ######\n\n" RESET);

	ft_debug_ld(e, &cursor[0]);
	ft_debug_ld2(e, &cursor[1]);
}
