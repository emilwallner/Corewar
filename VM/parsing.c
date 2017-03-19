/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:56:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/19 19:11:30 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**
** In this .c file, we gonna parse the data + check for errors
** We to get:
** 		- COREWAR_EXEC_MAGIC
**		- Name of the .cor
**		- Comments
**		- Instructions
**
*/

void ft_parsing(t_env *e, int ac)
{
	// int	error;
	int		i;
	int		k;
	int		hex;
	char	*str;
	char	*inst;

	i = 1;
	while (i < ac)
	{
// Look for COREWAR_EXEC_MAGIC
		// if (e->player[i].string[0] != ((COREWAR_EXEC_MAGIC & 0xFFFFFF) >> 16 & 0xFF))
			// printf("exit\n");

// Look for the Name
// Look for the Comments
// Instructions
	// printf("\n\nPlayer %i inst are:\n", i);
	k = PROG_NAME_LENGTH + COMMENT_LENGTH;
	str = e->player[i].string;
	inst = e->player[i].inst;
	while (!(str[k]))
		k++;
	e->player[i].inst_len = k;
    while(k < e->player[i].len)
	{
		hex = 0xFF & (str[k]);
		*inst = str[k];
		(hex <= 0xF) ? ft_printf("0%x", hex) : ft_printf("%x", hex);
		ft_putchar(' ');
		if ((k + 1) % 16 == 0)
			ft_printf("\n");
		k++;
		inst++;
	}
	e->player[i].inst_len = k - e->player[i].inst_len;
	ft_printf("\n\n");
	// printf("\n\ne->player[i].inst_len is %i\n\n", e->player[i].inst_len);
	i++;
	}
}

void ft_build_vm(t_env *e, int ac)
{
	int i;

	i = 1;
	while (i < ac)
	{
		ft_memcpy(e->arena + MEM_SIZE / (ac - 1) * (i - 1),
						e->player[i].inst, e->player[i].inst_len);
		e->player[i].index_start = MEM_SIZE / (ac - 1) * (i - 1);
		i++;
	}
	ft_print_hexa(e->arena, MEM_SIZE);
}
