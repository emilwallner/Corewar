/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_tools_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:16:15 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/31 12:50:32 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_init_v(t_env *e, t_cursor *cursor, t_var *v)
{
	v->r1 = 0;
	v->r2 = 0;
	v->r3 = 0;
	v->ind = 0;
	v->acb = e->a[MODA(cursor->index + 1)].hex;
	v->carry = 0;
}

int		is_reg_valid(int i)
{
	return (i > 0 && i <= REG_NUMBER);
}
