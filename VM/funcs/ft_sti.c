/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:49:37 by tlenglin          #+#    #+#             */
/*   Updated: 2017/04/02 16:20:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

#define RRD 0x58
#define RDD 0x68
#define RID 0x78

static int	rrd_rdr_rir(t_env *e, t_cursor *cursor, int acb, int *ind)
{
	int	r2;

	if (RRD == ZMASK(acb))
		r2 = get_reg(e, cursor, 3) + get_dir(e, cursor, 4, 2);
	else if (RDR == ZMASK(acb))
		r2 = get_dir(e, cursor, 3, 2) + get_reg(e, cursor, 5);
	else
		r2 = get_ind_sti(e, cursor, 3) + get_reg(e, cursor, 5);
	*ind = 6;
	return (r2);
}

static int	rdd_rid(t_env *e, t_cursor *cursor, int acb, int *ind)
{
	int	r2;

	if (RDD == ZMASK(acb))
		r2 = get_dir(e, cursor, 3, 2) + get_dir(e, cursor, 5, 2);
	else
		r2 = get_ind_sti(e, cursor, 3) + MODS((get_dir(e, cursor, 5, 2)));
	*ind = 7;
	return (r2);
}

static int	check_register(t_env *e, t_cursor *cursor, char acb)
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
	else if ((RDD == ZMASK(acb) || RID == ZMASK(acb)) &&
	!is_reg_valid(e->a[MODA(cursor->index + 2)].hex))
		return (0);
	return (1);
}

static void	set_arena(t_env *e, t_cursor *cursor, int r2, int acb)
{
	int	i;
	int reg_value;

	if (check_register(e, cursor, acb))
	{
		reg_value = cursor->reg[e->a[MODA(cursor->index + 2)].hex - 1];
		i = -1;
		while (++i < 4)
		{
			e->a[MODA((cursor->index + r2 + i))].hex =
			(reg_value >> (8 * (3 - i))) & 0xff;
			e->a[MODA((cursor->index + r2 + i))].color = cursor->color - 6;
			e->a[MODA((cursor->index + r2 + i))].prevcolor = cursor->color - 6;
			e->a[MODA((cursor->index + r2 + i))].new_color_count = 50;
		}
	}
}

void		ft_sti(t_env *e, t_cursor *cursor)
{
	char	acb;
	int		r2;
	int		ind;

	ind = 1;
	acb = e->a[MODA(cursor->index + 1)].hex;
	r2 = 0;
	if (RRR == ZMASK(acb))
	{
		r2 = get_reg(e, cursor, 3) + get_reg(e, cursor, 4);
		ind = 5;
	}
	else if (RRD == ZMASK(acb) || RDR == ZMASK(acb) || RIR == ZMASK(acb))
		r2 = rrd_rdr_rir(e, cursor, acb, &ind);
	else if (RDD == ZMASK(acb) || RID == ZMASK(acb))
		r2 = rdd_rid(e, cursor, acb, &ind);
	r2 = MODX(r2);
	set_arena(e, cursor, r2, acb);
	ft_update_cursor(e, cursor, ind);
}
