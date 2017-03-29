/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:40:56 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/29 18:28:51 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_lldi(t_env *e, t_cursor *cursor)
{
	char		acb;
	int			value;
	int			r2;
	int			ind;

	acb = e->a[MODA(cursor->index + 1)].hex;
	ind = 1;
	if (RRR == ZMASK(acb))
	{
			r2 = get_reg(e, cursor, 2) + get_reg(e, cursor, 3);
			// printf("RRR reg sum = %i  %x\n", r2, r2);
			ft_update_cursor(e, cursor, 4);
			ind = 4;
	}
	else if (RDR == ZMASK(acb) || DRR == ZMASK(acb) || IRR == ZMASK(acb))
		r2 = rdr_drr_irr(e, cursor, acb, &ind);
	else if (DDR == ZMASK(acb) || IDR == ZMASK(acb))
		r2 = ddr_idr(e, cursor, acb, &ind);
	if (check_register_ldi(e, cursor, acb))
	{
		value = get_bytes(e, cursor, cursor->index - ind + r2);
		cursor->reg[e->a[MODA(cursor->index)].hex - 1] = value;
		if (value == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
	ft_update_cursor(e, cursor, 1);
}
