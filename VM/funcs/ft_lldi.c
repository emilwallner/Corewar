/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:40:56 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/29 10:22:13 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_lldi(t_env *e, t_cursor *cursor)
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
	if (check_register_ldi(e, cursor, acb))
		cursor->reg[e->a[MODA(cursor->index)].hex - 1] = get_bytes(e, cursor, r2);
	ft_update_cursor(e, cursor, 1);
}
