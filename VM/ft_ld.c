/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/20 19:39:41 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Instructions:
** Take a random argument and a registry. Load the value of the first argument
** in the registry. Its opcode is 10 in binary and it will change the carry.
**
*/

void	ft_ld(char[30] copied_code, t_env *e, t_cursor *cursor)
{
	char	acb;

	acb = copied_code[1];
	if ((acb >> 6) == DIR_CODE)
	{
		cursor->reg[copied_code[2 + 4]] = (int*)(copied_code + 2);
		cursor->index += 6;
	}
	else
	{
		cursor->reg[copied_code[2 + 2]] = ((int*)(copied_code + 2) >> 8);
		cursor->index += 4;
	}
	cursor->carry = 1;
}
