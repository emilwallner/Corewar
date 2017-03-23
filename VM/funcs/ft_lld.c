/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:07:21 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/22 19:09:11 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
**
** Instructions:
** Means long-load. It the same as ld, but without % IDX_MOD.
** No % IDX_MOD
** Modify the carry
** OPC = 13
**
*/

void	ft_lld(char copied_code[30], t_env *e, t_cursor *cursor)
{
	int		acb;
	int		i = 0;

	(void)e;
	acb =  0xFF & copied_code[1];
	if ((acb >> 6) == DIR_CODE)
	{
		cursor->reg[copied_code[2 + 4]] = *(copied_code + 5);
		cursor->index += 6;
	}
	else
	{
		cursor->reg[copied_code[2 + 2]] = *(copied_code + *(copied_code + 3));
		cursor->index += 4;
	}
	cursor->carry = 1;
}
