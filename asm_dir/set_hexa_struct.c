/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:21:24 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/23 15:50:56 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_write_params	set_twp(t_asm tasm, t_op top, char *cell, int fd)
{
	t_write_params	twp;

	twp.tasm = tasm;
	twp.top = top;
	twp.cell = cell;
	twp.fd = fd;
	return (twp);
}

static void		increase_j(char *str, int *j)
{
	while (str[*j] && str[*j] != SEPARATOR_CHAR)
		(*j)++;
	(*j)++;
}

void			set_params(t_asm tasm, t_write *tw, char **tab, int fd)
{
	int				j;
	int				count;
	t_write_params	twp;

	count = -1;
	j = 0;
	while (tab[tw->is_label] && ++count < tasm.op_tab[tw->id_ins].nb_params)
	{
		if (tab[1 + tw->is_label][j] == 'r')
			set_register(tab[1 + tw->is_label] + j + 1, fd, &tw->cursor);
		else
		{
			twp = set_twp(tasm, tasm.op_tab[tw->id_ins],
				tab[1 + tw->is_label] + j, fd);
			twp.cur_cur = &tw->cursor;
			twp.ins_cursor = tw->instruction_cursor;
			if (tab[1 + tw->is_label][j] == '%')
				set_direct(&twp);
			else
				set_indirect(&twp);
		}
		increase_j(tab[1 + tw->is_label], &j);
	}
	tw->is_label = 0;
}
