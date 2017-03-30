/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:26:25 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/30 20:06:13 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Clearly, this function check if the args of the acb are correct
**
** If the last to digit are not blank => error
** Get the number of args and check if it's the one we were waiting for.
** Check if each args are valid
**
** We'll have to figure out how we handle the errors and what to do with the
** data that we get
*/

int	ft_check_args(t_env e, t_cursor cursor)
{
	int		nb_of_args;
	int		i;
	char	opcode;
	char	acb;

	i = -1;
	nb_of_args = 0;
	opcode = e.a[cursor.index].hex;
	acb = e.a[cursor.index + 1].hex;
// printf("for opcode is %i and acb is %#x\n", opcode, acb);

	if (e.op_tab[opcode].acb == 0)
		return (1);
	if (acb & 0x3)
		return (0);
		// printf("ERROR\n");
	while (++i < 3)
		if (acb >> (6 - i * 2) & 0x3)
			nb_of_args++;
	if (nb_of_args != e.op_tab[opcode].nb_params)
		return (0);
	// 	printf("ERROR NB OF ARGS");
	// printf("nb_of_args is %i\n", nb_of_args);
	i = 0;
	while (i < nb_of_args)
	{
		if ((acb >> (6 - i * 2) & 0x3) == REG_CODE &&
				(e.op_tab[opcode].params_type[i] & T_REG) == T_REG)
				;
			// printf("REG\n");
		else if ((acb >> (6 - i * 2) & 0x3) == DIR_CODE &&
				(e.op_tab[opcode].params_type[i] & T_DIR) == T_DIR)
				;
			// printf("DIR\n");
		else if ((acb >> (6 - i * 2) & 0x3) == IND_CODE &&
				(e.op_tab[opcode].params_type[i] & T_IND) == T_IND)
				;
			// printf("IND\n");
		else
			return (0);
			// printf("ERROR ARG - acb >> (6 - i * 2) is %i\n", acb >> (6 - i * 2));
		i++;
	}
	return (1);
}
