/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/29 10:52:39 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** Instructions: Acts like and with an exclusive OR. As you will have guessed,
** its opcode in octal is 10.
*/

static void	ft_xor_4(t_env *e, t_cursor *cursor, t_var v)
{
	if (ZMASK(v.acb) == DIR)
	{
		v.r1 = e->a[MODA(cursor->index + 8)].hex;
		if (ft_is_reg(v.r1 - 1, v.r1 - 1, v.r1 - 1) && (cursor->carry = 1))
			cursor->reg[v.r1 - 1] = get_dir(e, cursor, 2, 4) ^
				get_ind(e, cursor, 6);
		ft_update_cursor(e, cursor, 9);
	}
	else if (ZMASK(v.acb) == IIR)
	{
		v.r1 = e->a[MODA(cursor->index + 6)].hex;
		if (ft_is_reg(v.r1 - 1, v.r1 - 1, v.r1 - 1) && (cursor->carry = 1))
			cursor->reg[v.r1 - 1] = get_ind(e, cursor, 2) ^
				get_ind(e, cursor, 4);
		ft_update_cursor(e, cursor, 7);
	}
	else if (ZMASK(v.acb) == IDR)
	{
		v.r1 = e->a[MODA(cursor->index + 8)].hex;
		if (ft_is_reg(v.r1 - 1, v.r1 - 1, v.r1 - 1) && (cursor->carry = 1))
			cursor->reg[v.r1 - 1] = get_ind(e, cursor, 2) ^
				get_dir(e, cursor, 4, 4);
		ft_update_cursor(e, cursor, 9);
	}
}

static void	ft_xor_3(t_env *e, t_cursor *cursor, t_var v)
{
	if (ZMASK(v.acb) == DRR)
	{
		v.r1 = e->a[MODA(cursor->index + 6)].hex;
		v.r2 = e->a[MODA(cursor->index + 7)].hex;
		if (ft_is_reg(v.r1 - 1, v.r2 - 1, v.r2 - 1) && (cursor->carry = 1))
			cursor->reg[v.r2 - 1] = cursor->reg[v.r1 - 1] ^
				get_dir(e, cursor, 2, 4);
		ft_update_cursor(e, cursor, 8);
	}
	else if (ZMASK(v.acb) == DDR)
	{
		v.r1 = e->a[MODA(cursor->index + 10)].hex;
		if (ft_is_reg(v.r1 - 1, v.r1 - 1, v.r1 - 1) && (cursor->carry = 1))
			cursor->reg[v.r1 - 1] = get_dir(e, cursor, 2, 4) ^
				get_dir(e, cursor, 6, 4);
		ft_update_cursor(e, cursor, 11);
	}
	else
		ft_xor_4(e, cursor, v);
}

static void	ft_xor_2(t_env *e, t_cursor *cursor, t_var v)
{
	if (ZMASK(v.acb) == RIR)
	{
		v.r1 = e->a[MODA(cursor->index + 2)].hex;
		v.r2 = e->a[MODA(cursor->index + 5)].hex;
		if (ft_is_reg(v.r1 - 1, v.r2 - 1, v.r2 - 1) && (cursor->carry = 1))
			cursor->reg[v.r2 - 1] = cursor->reg[v.r1 - 1] ^
				get_ind(e, cursor, 3);
		ft_update_cursor(e, cursor, 6);
	}
	else if (ZMASK(v.acb) == IRR)
	{
		v.r1 = e->a[MODA(cursor->index + 4)].hex;
		v.r2 = e->a[MODA(cursor->index + 5)].hex;
		if (ft_is_reg(v.r1 - 1, v.r2 - 1, v.r2 - 1) && (cursor->carry = 1))
			cursor->reg[v.r2 - 1] = cursor->reg[v.r1 - 1] ^
				get_ind(e, cursor, 2);
		ft_update_cursor(e, cursor, 6);
	}
	else
		ft_xor_3(e, cursor, v);
}

void		ft_xor(t_env *e, t_cursor *cursor)
{
	t_var	v;

	v.acb = e->a[MODA(cursor->index + 1)].hex;
	if (ZMASK(v.acb) == RRR)
	{
		v.r1 = e->a[MODA(cursor->index + 2)].hex;
		v.r2 = e->a[MODA(cursor->index + 3)].hex;
		v.r3 = e->a[MODA(cursor->index + 4)].hex;
		if (ft_is_reg(v.r1 - 1, v.r2 - 1, v.r3 - 1) && (cursor->carry = 1))
			cursor->reg[v.r3 - 1] = cursor->reg[v.r1 - 1] ^
				cursor->reg[v.r2 - 1];
		ft_update_cursor(e, cursor, 5);
	}
	else if (ZMASK(v.acb) == RDR)
	{
		v.r1 = e->a[MODA(cursor->index + 2)].hex;
		v.r2 = e->a[MODA(cursor->index + 7)].hex;
		if (ft_is_reg(v.r1 - 1, v.r2 - 1, v.r2 - 1) && (cursor->carry = 1))
			cursor->reg[v.r2 - 1] = cursor->reg[v.r1 - 1] ^
				get_dir(e, cursor, 3, 4);
		ft_update_cursor(e, cursor, 8);
	}
	else
		ft_xor_2(e, cursor, v);
}
