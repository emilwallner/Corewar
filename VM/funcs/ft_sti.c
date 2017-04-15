/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:47:46 by mhaziza           #+#    #+#             */
/*   Updated: 2017/04/15 16:56:29 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

static int	is_valid(t_env *e, t_cursor *cursor, int jump)
{
	char	read;

	read = (char)(ZMASK(e->a[MODA(cursor->index + jump)].hex));
	if (read > 0 && read <= REG_NUMBER)
		return (1);
	return (0);
}

static int	read_hexa(t_env *e, t_cursor *cursor, char type, int jump)
{
	char	read1;
	short	read2;
	int		read4;

	if (type == REG_CODE)
	{
		read1 = ZMASK(e->a[MODA(cursor->index + jump)].hex);
		return (cursor->reg[read1 - 1]);
	}
	read2 = (short)(ZMASK(e->a[MODA(cursor->index + jump)].hex) << 8 |
			ZMASK(e->a[MODA(cursor->index + jump + 1)].hex));
	if (type == DIR_CODE)
		return ((int)read2);
	read2 = MODX(read2);
	read4 = (int)(ZMASK(e->a[MODA(cursor->index + read2)].hex) << 24 |
			ZMASK(e->a[MODA(cursor->index + read2 + 1)].hex) << 16 |
			ZMASK(e->a[MODA(cursor->index + read2 + 2)].hex) << 8 |
			ZMASK(e->a[MODA(cursor->index + read2 + 3)].hex));
	return (read4);
}

static int	get_terms(t_env *e, t_cursor *cursor, t_sti *s, char type)
{
	int		ret;

	ret = 1;
	if (type == REG_CODE && !is_valid(e, cursor, s->jump))
		ret = 0;
	else
		s->where += read_hexa(e, cursor, type, s->jump);
	s->jump = type == REG_CODE ? s->jump + 1 : s->jump + 2;
	return (ret);
}

static int	get_instruction(t_env *e, t_cursor *cursor, t_sti *s)
{
	char	reg;
	int		ret;
	char	type;

	ret = 1;
	reg = (char)(ZMASK(e->a[MODA(cursor->index + 2)].hex));
	if (!(reg > 0 && reg <= REG_NUMBER))
		return (0);
	s->value = cursor->reg[reg - 1];
	s->jump = 3;
	s->where = 0;
	s->acb = ZMASK(e->a[MODA(cursor->index + 1)].hex);
	type = (s->acb >> 4) & 3;
	if (!get_terms(e, cursor, s, type))
		ret = 0;
	type = (s->acb >> 2) & 3;
	if (!get_terms(e, cursor, s, type))
		ret = 0;
	s->where = MODX(s->where);
	return (ret);
}

void		ft_sti(t_env *e, t_cursor *curs)
{
	t_sti	s;
	int		i;

	if (get_instruction(e, curs, &s))
	{
		i = -1;
		while (++i < 4)
		{
			e->a[MODA((curs->index + s.where + i))].hex =
				(s.value >> (8 * (3 - i))) & 0xff;
			e->a[MODA((curs->index + s.where + i))].color = curs->color - 6;
			e->a[MODA((curs->index + s.where + i))].prevcolor = curs->color - 6;
			e->a[MODA((curs->index + s.where + i))].new_color_count = 50;
		}
	}
	ft_update_cursor(e, curs, s.jump);
}
