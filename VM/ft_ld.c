/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/21 19:07:04 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Instructions:
** Take a random argument and a registry. Load the value of the first argument
** in the registry. Its opcode is 10 in binary and it will change the carry.
**
*/

void	ft_ld(char copied_code[30], t_env *e, t_cursor *cursor)
{
	char	acb;
	int		i = 0;

	(void)e;
	printf("\n\n");
	// printf("sizeof(char) is %ld\n", sizeof(char));
	// printf("\ncopied_code[2 + 2] is %x\n", copied_code[2 + 2]);
	// printf("\nsizeof(copied_code[2 + 2]) is %ld\n", sizeof(copied_code[2 + 2]));
	// printf("copied_code[2 + 2] is %i\n", copied_code[2 + 2]);
	while (i < 5)
	{
		ft_printf("%02.x ", (copied_code[i] & 0xFF));
		i++;
	}

	acb = copied_code[1];
	if ((acb >> 6) == DIR_CODE)
	{
		cursor->reg[(int)copied_code[2 + 4]] = *(int*)(copied_code + 2);
		cursor->index += 6;
	}
	else
	{
		cursor->reg[(int)copied_code[2 + 2]] = (*(int*)(copied_code + 2) >> 8);
		cursor->index += 4;
	}
	cursor->carry = 1;
}
