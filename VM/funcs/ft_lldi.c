/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:40:56 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/28 09:38:26 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

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
	// r2 = MODX(r2);
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
	// r2 = MODX(r2);
	return (r2);
}

void	ft_lldi(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			value;
	int			index;
	int			r2;
	short int	ind_value;

	acb = e->a[MODA(cursor->index + 1)].hex;
	index = 4;
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
	else
	{
		ft_update_cursor(e, cursor, 1);
		return ;
	}
	cursor->reg[e->a[MODA(cursor->index)].hex] = get_bytes(e, cursor, r2);

	ft_update_cursor(e, cursor, 1);
}
