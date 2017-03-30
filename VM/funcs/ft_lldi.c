/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:40:56 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/30 19:53:03 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

static void	ft_load(t_env *e, t_cursor *cursor, int ind, int r2)
{
	int			value;

	value = get_bytes(e, cursor, cursor->index - ind + r2);
	cursor->reg[e->a[MODA(cursor->index)].hex - 1] = value;
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}

void		ft_lldi(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			r2;
	int			ind;

	acb = e->a[MODA(cursor->index + 1)].hex;
	ind = 1;
	if (RRR == ZMASK(acb))
	{
		r2 = get_reg(e, cursor, 2) + get_reg(e, cursor, 3);
		ft_update_cursor(e, cursor, 4);
		ind = 4;
	}
	else if (RDR == ZMASK(acb) || DRR == ZMASK(acb) || IRR == ZMASK(acb))
		r2 = rdr_drr_irr(e, cursor, acb, &ind);
	else if (DDR == ZMASK(acb) || IDR == ZMASK(acb))
		r2 = ddr_idr(e, cursor, acb, &ind);
	if (check_register_ldi(e, cursor, acb))
		ft_load(e, cursor, ind, r2);
	ft_update_cursor(e, cursor, 1);
}
