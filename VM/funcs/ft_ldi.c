/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 11:36:50 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

// #define RRR 0x54
// #define RDR 0x64
// #define DRR 0x94
// #define DDR 0xa4
// #define IRR 0xd4
// #define IDR 0xe4

/*
** Instructions:
**
** ldi, its code is 0x0a. Instead, it will use 2 indexes and 1 registry,
** adding the first two, treating that like an address, reading a value of a
** registry’s size and putting it on the third.
**
*/
static int	rdr_drr_irr(t_env *e, t_cursor *cursor, int acb)
{
	int	r2;
	if (RDR == ZMASK(acb))
	{
		r2 = get_reg(e, cursor, 2) + get_dir(e, cursor, 3, 2);
		// printf("RDR R= %i D= %i reg sum = %i  %x\n", get_reg(e, cursor, 2), get_dir(e, cursor, 3, 2),r2, r2);
	}
	else if (DRR == ZMASK(acb))
	{
		r2 = get_dir(e, cursor, 2, 2) + get_reg(e, cursor, 4);
		// printf("RDR R= %x D= %x R+D = %i  %x\n", get_reg(e, cursor, 4), get_dir(e, cursor, 2, 2),r2, r2);
	}
	else
	{
		r2 = get_ind(e, cursor, 2) + get_reg(e, cursor, 4);
		// printf("IRR R= %x I= %x R+I = %i  %x\n", get_reg(e, cursor, 4), get_ind(e, cursor, 2),r2, r2);
	}
	ft_update_cursor(e, cursor, 5);
	return (r2);
}

static int	ddr_idr(t_env *e, t_cursor *cursor, int acb)
{
	int	r2;

	if (DDR == ZMASK(acb))
	{
		r2 = get_dir(e, cursor, 2, 2) + get_dir(e, cursor, 4, 2);
		// printf("DDR D= %x D= %x D+D = %i  %x\n", get_dir(e, cursor, 4, 2), get_dir(e, cursor, 2, 2),r2, r2);
	}
	else
	{
		r2 = get_ind(e, cursor, 2) + get_dir(e, cursor, 4, 2);
		// printf("IDR D= %x I= %x D+I = %i  %x\n", get_dir(e, cursor, 4, 2), get_ind(e, cursor, 2),r2, r2);
	}
	ft_update_cursor(e, cursor, 6);
	return (r2);
}

int check_register_ldi(t_env *e, t_cursor *cursor, char acb)
{
	if (RRR == ZMASK(acb) && (!is_reg_valid(e->a[MODA(cursor->index + 2)].hex ||
	!is_reg_valid(e->a[MODA(cursor->index + 3)].hex)) ||
	!is_reg_valid(e->a[MODA(cursor->index + 4)].hex)))
		return (0);
	else if (RDR == ZMASK(acb) &&
	(!is_reg_valid(e->a[MODA(cursor->index + 2)].hex) ||
	!is_reg_valid(e->a[MODA(cursor->index + 5)].hex)))
		return (0);
	else if ((DRR == ZMASK(acb) || IRR == ZMASK(acb)) &&
	(!is_reg_valid(e->a[MODA(cursor->index + 4)].hex) ||
	!is_reg_valid(e->a[MODA(cursor->index + 5)].hex)))
		return (0);
	return (1);
}

void	ft_ldi(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			value;
	int			r2;
	short int	ind_value;

	acb = e->a[MODA(cursor->index + 1)].hex;
	if (RRR == ZMASK(acb))
	{
			r2 = get_reg(e, cursor, 2) + get_reg(e, cursor, 3);
			// printf("RRR reg sum = %i  %x\n", r2, r2);
			ft_update_cursor(e, cursor, 4);
	}
	else if (RDR == ZMASK(acb) || DRR == ZMASK(acb) || IRR == ZMASK(acb))
		r2 = rdr_drr_irr(e, cursor, acb);
	else if (DDR == ZMASK(acb) || IDR == ZMASK(acb))
		r2 = ddr_idr(e, cursor, acb);
	r2 = MODX(r2);
	if (check_register_ldi(e, cursor, acb))
		cursor->reg[e->a[MODA(cursor->index)].hex - 1] = get_bytes(e, cursor, r2);
	ft_update_cursor(e, cursor, 1);
}
