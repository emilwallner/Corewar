/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/31 22:07:09 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions:
** ldi, its code is 0x0a. Instead, it will use 2 indexes and 1 registry,
** adding the first two, treating that like an address, reading a value of a
** registry’s size and putting it on the third.
*/

int			rdr_drr_irr(t_env *e, t_cursor *cursor, int acb, int *ind)
{
	int	r2;

	if (RDR == ZMASK(acb))
		r2 = get_reg(e, cursor, 2) + get_dir(e, cursor, 3, 2);
	else if (DRR == ZMASK(acb))
		r2 = get_dir(e, cursor, 2, 2) + get_reg(e, cursor, 4);
	else
		r2 = get_ind(e, cursor, 2) + get_reg(e, cursor, 4);
	*ind = 5;
	ft_update_cursor(e, cursor, 5);
	return (r2);
}

int			ddr_idr(t_env *e, t_cursor *cursor, int acb, int *ind)
{
	int	r2;

	if (DDR == ZMASK(acb))
		r2 = get_dir(e, cursor, 2, 2) + get_dir(e, cursor, 4, 2);
	else
		r2 = get_ind(e, cursor, 2) + get_dir(e, cursor, 4, 2);
	*ind = 6;
	ft_update_cursor(e, cursor, 6);
	return (r2);
}

int			check_register_ldi(t_env *e, t_cursor *cursor, char acb)
{
	if (RRR == ZMASK(acb) && (!is_reg_valid(e->a[MODA(cursor->index)].hex ||
	!is_reg_valid(e->a[MODA(cursor->index - 1)].hex)) ||
	!is_reg_valid(e->a[MODA(cursor->index + 1)].hex)))
		return (0);
	else if (RDR == ZMASK(acb) &&
	(!is_reg_valid(e->a[MODA(cursor->index - 2)].hex) ||
	!is_reg_valid(e->a[MODA(cursor->index + 1)].hex)))
		return (0);
	else if ((DRR == ZMASK(acb) || IRR == ZMASK(acb)) &&
	(!is_reg_valid(e->a[MODA(cursor->index)].hex) ||
	!is_reg_valid(e->a[MODA(cursor->index + 1)].hex)))
		return (0);
	else if (DDR == ZMASK(acb) &&
	!is_reg_valid(e->a[MODA((cursor->index + 1))].hex))
		return (0);
	return (1);
}

static void	ft_load(t_env *e, t_cursor *cursor, int ind, int r2)
{
	int			value;

	value = get_bytes(e, cursor, cursor->index - ind + r2);
	if (is_reg_valid(e->a[MODA(cursor->index)].hex - 1))
		cursor->reg[e->a[MODA(cursor->index)].hex - 1] = value;
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}

void		ft_ldi(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			r2;
	int			ind;

	ind = 1;
	acb = e->a[MODA(cursor->index + 1)].hex;
	r2 = 0;
	if (RRR == ZMASK(acb))
	{
		r2 = get_reg(e, cursor, 2) + get_reg(e, cursor, 3);
		ind = 4;
		ft_update_cursor(e, cursor, 4);
	}
	else if (RDR == ZMASK(acb) || DRR == ZMASK(acb) || IRR == ZMASK(acb))
		r2 = rdr_drr_irr(e, cursor, acb, &ind);
	else if ((DDR == ZMASK(acb) || IDR == ZMASK(acb)))
		r2 = ddr_idr(e, cursor, acb, &ind);
	r2 = MODX(r2);
	if (check_register_ldi(e, cursor, acb))
		ft_load(e, cursor, ind, r2);
	ft_update_cursor(e, cursor, 1);
}
