/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:23:13 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/23 16:30:11 by nsabbah          ###   ########.fr       */
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
	cursor->operation[0] = 0x02;
	cursor->operation[1] = 0xd0;
	cursor->operation[2] = 0x00;
	cursor->operation[3] = 0x0a;
	cursor->operation[4] = 0x02;
	cursor->operation[5] = 0x02;
	cursor->operation[6] = 0xd0;
	cursor->operation[7] = 0x00;
	cursor->operation[8] = 0x0a;
	cursor->operation[9] = 0x02;
	cursor->operation[10] = 0xff;
	cursor->operation[11] = 0xff;
	cursor->operation[12] = 0xff;
	cursor->operation[13] = 0x01;

	printf(CYAN "INFO : Test with IND, write value of index + 10 in R2\n\n" RESET);
	printf("Data: \n");
	while (i < 14)
	{
		ft_printf("%02.x ", (cursor->operation[i] & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[2] = 8;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[2] %i\n", cursor->reg[2]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_ld(cursor->operation, &e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	printf("reg[2] %i\n", cursor->reg[2]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);
}

void	ft_debug_ld2(t_env e, t_cursor *cursor)
{
	// From the asm : 02 90 00 00 00 0a 02
	int i = 0;
	cursor->operation[0] = 0x02;
	cursor->operation[1] = 0x90;
	cursor->operation[2] = 0x00;
	cursor->operation[3] = 0x0f;
	cursor->operation[4] = 0x72;
	cursor->operation[5] = 0x63;
	cursor->operation[6] = 0x02;

	printf(CYAN "\nINFO : Test with DIR (4 bytes), write value in R2\n\n" RESET);
	printf("Data: \n");
	while (i < 7)
	{
		ft_printf("%02.x ", (cursor->operation[i] & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[2] = 8;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[2] %i\n", cursor->reg[2]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_ld(cursor->operation, &e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	printf("reg[2] %i\n", cursor->reg[2]);
	printf("carry is %i\n", cursor->carry);
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
