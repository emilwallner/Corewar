/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:23:13 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/23 11:10:59 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** This part is to test each function while the core algo is being built
*/
void	ft_debug(t_env e)
{
	t_cursor *cursor;
	int i = 0;

	cursor = (t_cursor*)malloc(sizeof(*cursor));
	cursor->index = 0;

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
	cursor->operation[10] = 0x02;
	i = 0;
	printf("\n");
	printf("\nOutput: \n");
	while (i < 11)
	{
		ft_printf("%02.x ", (cursor->operation[i] & 0xFF));
		i++;
	}
	printf("\n");
	cursor->reg[1] = 5;
	cursor->reg[2] = 8;
	cursor->reg[3] = 9;
	printf("cursor->reg[2] %i\n", cursor->reg[2]);
	ft_ld(cursor->operation, &e, cursor);
	printf("\n");
	printf("cursor->carry is %i\n", cursor->carry);
	printf("cursor->reg[2] %i\n", cursor->reg[2]);
}
