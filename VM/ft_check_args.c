/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:26:25 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/19 18:42:51 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

ft_check_args(int opcode, int acb)
{
	int	nb_of_args;
	int	i;

	i = -1;
	nb_of_args = 0;

/*
** Get the number of args and check if it's the one we were waiting for.
*/
	while (++i < 3)
		if (acb >> (6 - i * 2) & 0x3)
			nb_of_args++;
	if (nb_of_args != g_op_tab[opcode][1])
		printf("ERROR")
/*
** Check if each args are valid
*/
	i = 0;
	while (i < nb_of_args)
	{
		if (acb >> (6 - i * 2) == REG_CODE &&
				g_op_tab[opcode][2][i] & T_REG == T_REG)
			printf("REG ");
		else if (acb >> (6 - i * 2) == DIR_CODE &&
				g_op_tab[opcode][2][i] & T_DIR == T_DIR)
			printf("DIR ");

		else if (acb >> (6 - i * 2) == IND_CODE &&
				g_op_tab[opcode][2][i] & T_IND == T_IND)
			printf("IND ");
		else
			printf("ERROR\n");
		i++;
	}
}
