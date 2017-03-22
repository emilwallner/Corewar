/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:23:13 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/21 19:12:17 by nsabbah          ###   ########.fr       */
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
	cursor = malloc (sizeof(cursor));
	// (void)e;
	// (void)cursor;
	printf(" HELLO\n");
	cursor->index = 0;
	// strncpy(cursor->operation, e.arena, 30);
	while (i < 6)
	{
		cursor->operation[i] = e.arena[i];
		i++;
	}

	i = 0;
	printf(" HELLO\n");
	while (i < 6)
	{
		ft_printf("%02.x ", (e.arena[i] & 0xFF));
		i++;
	}

	i = 0;
	printf("\n\n");

	while (i < 6)
	{
		ft_printf("%02.x ", (cursor->operation[i] & 0xFF));
		i++;
	}
	printf("\n\n");
	cursor->reg[0] = 1;
	cursor->reg[1] = 5;
	cursor->reg[2] = 8;
	cursor->reg[3] = 9;
	ft_ld(cursor->operation, &e, cursor);
	printf("cursor->carry is %i\n", cursor->carry);
	printf("cursor->reg[2] %i\n", cursor->reg[2]);
}
