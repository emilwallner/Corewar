/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/22 15:49:59 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions:
** Take a random argument and a registry. Load the value of the first argument
** in the registry. Its opcode is 10 in binary and it will change the carry.
**
*/

void	ft_ld(char copied_code[30], t_env *e, t_cursor *cursor)
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
