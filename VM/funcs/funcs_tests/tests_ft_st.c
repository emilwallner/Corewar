/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:31:16 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 13:46:18 by mhaziza          ###   ########.fr       */
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
	e.a[3].hex = 0x02;
	e.a[4].hex = 0xff;
	e.a[5].hex = 0xff;
	e.a[6].hex = 0xfe;
	e.a[7].hex = 0x00;
	e.a[8].hex = 0x00;


	// printf("%+.60x\n", 1234);

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
	printf("reg[2] %i\n", cursor->reg[2]);
	printf("carry is %i\n", cursor->carry);
	printf("index is %i\n", cursor->index);
}
