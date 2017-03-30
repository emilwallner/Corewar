/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:49:37 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/30 12:19:10 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

// #define RRR 0x54
#define RRD 0x58
// #define RDR 0x64
#define RDD 0x68
// #define RIR 0x74
#define RID 0x78

int get_ind_sti(t_env *e, t_cursor *cursor, int i)
{
	unsigned short	r;

	r = ((ZMASK(e->a[MODA(i)].hex) << 8) | ZMASK(e->a[MODA(i + 1)].hex));
	r = cursor->index + (short)r;
	return (MODA(get_bytes(e, cursor, r)));
}

static int	rrd_rdr_rir(t_env *e, t_cursor *cursor, int acb, int *ind)
{
	int	r2;

	if (RRD == ZMASK(acb))
	{
		r2 = get_reg(e, cursor, 3) + get_dir(e, cursor, 4, 2);
		// printf("RRD R= %i D= %i reg sum = %i  %x\n", get_reg(e, cursor, 3), get_dir(e, cursor, 4, 2),r2, r2);
	}
	else if (RDR == ZMASK(acb))
	{
		r2 = get_dir(e, cursor, 3, 2) + get_reg(e, cursor, 5);
		// printf("RDR R= %x D= %x R+D = %i  %x\n", get_reg(e, cursor, 5), get_dir(e, cursor, 3, 2),r2, r2);
	}
	else
	{
		r2 = get_ind_sti(e, cursor, cursor->index + 3) + get_reg(e, cursor, 5);
		// printf("RIR R= %x I= %x R+I = %i  %x\n", get_reg(e, cursor, 5), get_ind(e, cursor, cursor->index + 3),r2, r2);
	}
	*ind = 6;
	return (r2);
}

static int	rdd_rid(t_env *e, t_cursor *cursor, int acb, int *ind)
{
	int	r2;

	if (RDD == ZMASK(acb))
	{
		r2 = get_dir(e, cursor, 3, 2) + get_dir(e, cursor, 5, 2);
		// printf("RDD D= %x D= %x D+D = %i  %x\n", get_dir(e, cursor, 3, 2), get_dir(e, cursor, 5, 2),r2, r2);
	}
	else
	{
		r2 = get_ind_sti(e, cursor, cursor->index + 3) + get_dir(e, cursor, 5, 2);
		// printf("RID D= %x I= %x D+I = %i  %x\n", get_dir(e, cursor, 5, 2), get_ind(e, cursor, cursor->index + 3), r2, r2);
	}
	*ind = 7;
	return (r2);
}

int is_reg_valid(int i)
{
	return (i > 0 && i <  REG_NUMBER);
}

static int check_register(t_env *e, t_cursor *cursor, char acb)
{
	if (!is_reg_valid(e->a[MODA(cursor->index + 2)].hex))
		return (0);
	if (RRR == ZMASK(acb) && (!is_reg_valid(e->a[MODA(cursor->index + 3)].hex ||
	!is_reg_valid(e->a[MODA(cursor->index + 4)].hex))))
		return (0);
	else if (RRD == ZMASK(acb) &&
	!is_reg_valid(e->a[MODA(cursor->index + 3)].hex))
		return (0);
	else if ((RDR == ZMASK(acb) || RIR == ZMASK(acb)) &&
	!is_reg_valid(e->a[MODA(cursor->index + 5)].hex))
		return (0);
	return (1);
}

void	ft_sti(t_env *e, t_cursor *cursor)
{
	char	acb;
	int		r;
	int		i;
	int		r2;
	int		ind;

	ind = 1;
	acb = e->a[MODA(cursor->index + 1)].hex;
	r = cursor->reg[e->a[MODA(cursor->index + 2)].hex - 1];
	if (RRR == ZMASK(acb))
	{
			r2 = get_reg(e, cursor, 3) + get_reg(e, cursor, 4);
			ind = 5;
			// printf("RRR reg sum = %i  %x\n", r2, r2);
	}
	else if (RRD == ZMASK(acb) || RDR == ZMASK(acb) || RIR == ZMASK(acb))
		r2 = rrd_rdr_rir(e, cursor, acb, &ind);
	else if (RDD == ZMASK(acb) || RID == ZMASK(acb))
		r2 = rdd_rid(e, cursor, acb, &ind);
	r2 = MODX(r2);
	i = -1;
	while (++i < 4 && check_register(e, cursor, acb))
	{
		e->a[MODA((cursor->index + r2 + i))].hex = r >> (8 * (3 - i));
		e->a[MODA((cursor->index + r2 + i))].color = cursor->color - 6;
		e->a[MODA((cursor->index + r2 + i))].prevcolor = cursor->color - 6;
		e->a[MODA((cursor->index + r2 + i))].new_color_count = 50;
	}
	ft_update_cursor(e, cursor, ind);
}
