/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:31:16 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/27 16:51:47 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/vm.h"

void	ft_tests_sub(t_env e, t_cursor *cursor)
{
	int i = 0;
	// Building the fake copied code:
	e.a[0].hex = 0x04;
	e.a[1].hex = 0x54;
	e.a[2].hex = 0x03;
	e.a[3].hex = 0x03;
	e.a[4].hex = 0x03;

	printf(CYAN "INFO : Multiple reg[3] by 2\n\n" RESET);
	printf("Data: \n");
	while (i < 4)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[3] = 8;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[3] %i\n", cursor->reg[3]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_sub(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	printf("reg[3] %i (expected: 0)\n", cursor->reg[3]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 5)\n", cursor->index);
}

void	ft_tests_sub2(t_env e, t_cursor *cursor)
{
	int i = 0;
	// Building the fake copied code:
	e.a[0].hex = 0x04;
	e.a[1].hex = 0x54;
	e.a[2].hex = 0x02;
	e.a[3].hex = 0x03;
	e.a[4].hex = 0x04;

	printf(CYAN "INFO : subs reg[2] and reg[3] in reg[4] by 2\n\n" RESET);
	printf("Data: \n");
	while (i < 4)
	{
		ft_printf("%02.x ", (e.a[i].hex & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[2] = 1;
	cursor->reg[3] = 2;
	cursor->reg[4] = 8;
	cursor->index = 0;

	printf("\nBEFORE FUNCTION CALL\n\n");

	printf("reg[2] %i\n", cursor->reg[2]);
	printf("reg[3] %i\n", cursor->reg[3]);
	printf("reg[4] %i\n", cursor->reg[4]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);

	ft_sub(&e, cursor);

	printf("\n\nAFTER FUNCTION CALL\n\n");
	printf("reg[4] %i (expected: -1)\n", cursor->reg[4]);
	printf("carry is %i (expected: 1)\n", cursor->carry);
	printf("index is %i (expected: 5)\n", cursor->index);
}
