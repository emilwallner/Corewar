/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:31:16 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 16:21:12 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/vm.h"

void	ft_tests_st(t_env e, t_cursor *cursor)
{
	int i = 0;
	// Building the fake copied code:
	e.a[0].hex = 0x03;
	e.a[1].hex = 0x70;

	e.a[2].hex = 0x01;

	e.a[3].hex = 0x00;
	e.a[4].hex = 0x0d;

	e.a[5].hex = 0x03;
	e.a[6].hex = 0x70;
	e.a[7].hex = 0x01;
	e.a[8].hex = 0xfc;
	e.a[9].hex = 0x18;

	e.a[10].hex = 0x03;
	e.a[11].hex = 0x70;
	e.a[12].hex = 0x01;
	e.a[13].hex = 0xff;

	e.a[14].hex = 0x9c;
	e.a[15].hex = 0x03;
	e.a[16].hex = 0x70;
	e.a[17].hex = 0x01;
	e.a[18].hex = 0x00;
	e.a[19].hex = 0x32;


	// printf("%+.60x\n", 1234);

	printf(CYAN "INFO : Test with IND, write value of index + 10 in R2\n\n" RESET);
	printf("Data: \n");
	while (i < 14)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[0] = 0xffffffff;
	cursor->reg[1] = 0xffffffff;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[1] %i\n", cursor->reg[1]);
	// printf("reg[2] %i (expected: ?)\n", cursor->reg[2]);

	// printf("carry is %i\n", cursor->carry);
	// printf("index is %i\n", cursor->index);

	ft_st(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	i = 0;
	while (i < 4)
	{
		printf("e.a[10 + i] %x \n", e.a[10 + i].hex & 0xff);
		i++;
	}
	// printf("reg[2] %i\n", cursor->reg[2]);
	// printf("carry is %i\n", cursor->carry);
	// printf("index is %i\n", cursor->index);
}
