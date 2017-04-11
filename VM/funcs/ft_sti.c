/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:43:04 by mhaziza           #+#    #+#             */
/*   Updated: 2017/04/11 21:13:18 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

#define RRD 0x58
#define RDD 0x68
#define RID 0x78

int read_hexa(t_cursor *cursor,t_env *e,  char type, int start)
{
	unsigned short s_value;
	unsigned int value;
	int ret;
	int adresse;

	ret = 0;
	if (type == T_DIR)
	{
		s_value = (ZMASK(e->a[MODA(start)].hex) << 8) |
				ZMASK(e->a[MODA(start + 1)].hex);
		ret = (short)s_value;
		ret = (int)s_value;
	}
	else if (type == T_IND)
	{
		s_value = (ZMASK(e->a[MODA(start)].hex) << 8) |
				ZMASK(e->a[MODA(start + 1)].hex);
		s_value = (short)s_value;
		value =(ZMASK(e->a[MODA(cursor->index + s_value)].hex) << 24) |
		(ZMASK(e->a[MODA((cursor->index + s_value + 1))].hex) << 16) |
		(ZMASK(e->a[MODA((cursor->index + s_value + 2))].hex) << 8) |
		ZMASK(e->a[MODA((cursor->index + s_value + 3))].hex);
		ret = (int)value;
	}
	else if (type == T_REG)
	{
		adresse = ZMASK(e->a[MODA(start)].hex);
		value = cursor->reg[adresse - 1];
		ret = value;
	}
	return (MODX(ret));
}

void	set_arena(t_env *e, t_cursor *cursor, int value)
{
	int	i;
	int reg_value;

	reg_value = cursor->reg[e->a[MODA(cursor->index + 2)].hex - 1];
	i = -1;
	while (++i < 4)
	{
		e->a[MODA((cursor->index + value + i))].hex =
		(reg_value >> (8 * (3 - i))) & 0xff;
		e->a[MODA((cursor->index + value + i))].color = cursor->color - 6;
		e->a[MODA((cursor->index + value + i))].prevcolor = cursor->color - 6;
		e->a[MODA((cursor->index + value + i))].new_color_count = 50;
	}
}

void		ft_sti(t_env *e, t_cursor *cursor)
{
	char	acb;
	int		jump;
	int		ind;
	int		cidx;

	cidx = cursor->index;
	ind = 1;
	acb = e->a[MODA(cidx + 1)].hex;
 	jump = 0;
	if (!is_reg_valid(e->a[MODA(cidx + 2)].hex))
		jump = 1;
	else if (RRR == ZMASK(acb))
	{
		if (is_reg_valid(e->a[MODA(cidx + 3)].hex) && is_reg_valid(e->a[MODA(cidx + 4)].hex))
			jump = read_hexa(cursor, e, T_REG, cidx + 3) + read_hexa(cursor, e, T_REG, cidx + 4);
			// printf("RRR = %x %i\n", jump, jump);
		ind = 5;
	}
	else if (RRD == ZMASK(acb))
	{
		if (is_reg_valid(e->a[MODA(cidx + 3)].hex))
			jump = read_hexa(cursor, e, T_REG, cidx + 3) + read_hexa(cursor, e, T_DIR, cidx + 4);
			// printf("RRD = %x %i\n", jump, jump);
		ind = 5;
	}
	else if (RDR == ZMASK(acb) || RIR == ZMASK(acb))
	{
		if (is_reg_valid(e->a[MODA(cidx + 5)].hex))
		{
			if (RDR == ZMASK(acb))
				jump = read_hexa(cursor, e, T_DIR, cidx + 3) + read_hexa(cursor, e, T_REG, cidx + 5);
			else
				jump = read_hexa(cursor, e, T_IND, cidx + 3) + read_hexa(cursor, e, T_REG, cidx + 5);
			ind = 5;
		}
		// printf("RDR/RIR = %x %i\n", jump, jump);
	}
	else if (RDD == ZMASK(acb))
	{
		jump = read_hexa(cursor, e, T_DIR, cidx + 3) + read_hexa(cursor, e, T_DIR, cidx + 5);
		ind = 7;
		// printf("RDD = %x %i\n", jump, jump);
	}
	else if (RID == ZMASK(acb))
	{
		jump = read_hexa(cursor, e, T_IND, cidx + 3) + read_hexa(cursor, e, T_DIR, cidx + 5);
		ind = 7;
		// printf("RID = %i %i\n", MODX(jump), jump);
	}
	jump = MODX(jump);
	// printf("MODX(jump) = %x %i\n", jump, jump);
	// printf("final %i \n", (value));
	set_arena(e, cursor, jump);
	ft_update_cursor(e, cursor, ind);
}
