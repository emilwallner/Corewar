/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/23 17:31:51 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions:
** Take a random argument and a registry. Load the value of the first argument
** in the registry. Its opcode is 10 in binary and it will change the carry.
**
** Should the IND part should be % MEM_SIZE or similar?
*/

int		ft_cp_int(char *int_start)
{
	int i;
	int value;

	i = 4;
	value = 0;
	while (--i >= 0)
		value += *((int_start + (3 - i))) << (i * 8);
	return (value);
}
void	ft_ld(char copied_code[30], t_env *e, t_cursor *cursor)
{
	int		acb;
	int		i;
	int		value;
	char	*value_position;

	(void)e;
	i = 4;
	value_position = copied_code;
	acb =  0xFF & copied_code[1];
	if ((acb >> 6) == DIR_CODE)
	{
		value_position += 2;
		value = ft_cp_int(value_position);
		cursor->reg[copied_code[2 + 4]] = value;
		cursor->index += 7;
	}
	else
	{
		value_position += (*(copied_code + 3) % IDX_MOD);
		value = ft_cp_int(value_position);
		cursor->reg[copied_code[2 + 2]] = value;
		cursor->index += 5;
	}
	cursor->carry = 1;
}
