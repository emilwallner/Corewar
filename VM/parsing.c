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
		k++;
		inst++;
	}
	e->player[i].inst_len = k - e->player[i].inst_len;
	i++;
	}
}

void ft_player_to_arena(t_env *e, int i, int *k)
{
	int count;

	count = 0;
	while(count < e->player[i].inst_len)
	{
		e->a[*k].hex = 0xFF & e->player[i].inst[count];
		e->a[*k].color = i % 6;
		e->a[i].prevcolor = i % 6;
		*k += 1;
		count++;
	}
}

void ft_build_vm(t_env *e, int ac)
{
	int i;
	static int k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		e->player[i].index_start = MEM_SIZE / (ac - 1) * (i - 1);
		k = MEM_SIZE / (ac - 1) * (i - 1);
		ft_player_to_arena(e, i, &k);
		i++;
	}
	ft_print_hexa(e);
}
