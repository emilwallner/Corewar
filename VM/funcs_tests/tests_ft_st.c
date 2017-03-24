/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:31:16 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 18:22:48 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_debug_st(t_env e, t_cursor *cursor)
{
	int i = 0;
	// Building the fake copied code:
	e.a[0].hex = 0x03;
	e.a[1].hex = 0x70;
	e.a[2].hex = 0x01;
	e.a[3].hex = 0x02;
	e.a[4].hex = 0x03;
	e.a[5].hex = 0x70;
	e.a[6].hex = 0x01;
	e.a[7].hex = 0x00;
	e.a[8].hex = 0x00;
	e.a[4].hex = 0x03;
	e.a[5].hex = 0x70;
	e.a[6].hex = 0x01;
	e.a[7].hex = 0x00;
	e.a[8].hex = 0x00;
	e.a[4].hex = 0x03;
	e.a[5].hex = 0x70;
	e.a[6].hex = 0x01;
	e.a[7].hex = 0x00;
	e.a[8].hex = 0x00;

	printf("%+.60y\n", 1234);

	printf(CYAN "INFO : Test with IND, write value of index + 10 in R2\n\n" RESET);
	printf("Data: \n");
	while (i < 14)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[1] = 300;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	printf("reg[2] %i (expected: ?)\n", cursor->reg[2]);

	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_st(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	printf("reg[2] %i (expected: ?)\n", cursor->reg[2]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i\n", cursor->index);
}

void	ft_debug_st2(t_env e, t_cursor *cursor)
{
	// From the asm : 02 90 00 00 00 0a 02
	int i = 0;
	e.a[0].hex = 0x03;
	e.a[1].hex = 0x50;
	e.a[2].hex = 0x01;
	e.a[3].hex = 0x02;
	e.a[4].hex = 0x03;
	e.a[5].hex = 0x70;
	e.a[6].hex = 0x01;
	e.a[7].hex = 0x00;
	e.a[8].hex = 0x0a;

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
