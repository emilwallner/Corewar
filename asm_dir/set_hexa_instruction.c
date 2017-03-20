/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:45:44 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/20 16:58:32 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static char	g_opcode_hex[17] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

int	set_opcode(t_asm tasm,char *line, int fd, int *cursor)
{
	int		id;

	if (!(id = get_id_by_name(&tasm, line)))
	{
		return (0);
	}
	// printf("line = %s id = %i\n", line, id);
	ft_putchar_fd(id, fd);
	*cursor += 1;
	return (id);
}

void	set_acb(t_op top, char *line, int fd, int *cursor)
{
	// printf("top set_abc %s\n", top.name);
	unsigned char	acb;
	int				i;
	int				j;

	i = -1;
	acb = 0;
	j = 0;
	while (++i < top.nb_params)
	{
		if (line[0] == 'r')
			acb = acb + (REG_CODE << ((3 - i) * 2));
		else if (line[0] == '%')
			acb = acb + (DIR_CODE << ((3 - i) * 2));
		else
			acb = acb + (IND_CODE << ((3 - i) * 2));
		line = ft_strchr(line, SEPARATOR_CHAR) ? ft_strchr(line, SEPARATOR_CHAR) + 1 : line;
		// printf("racb %i\n", acb);
	}
	ft_putchar_fd(acb, fd);
	*cursor += 1;
	// ft_putnbr_base(acb, 2);
	// printf("acb %i\n", acb);
}

int		begin_by_label(char *line)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = ft_strchr(line, LABEL_CHAR) ? ft_strchr(line, LABEL_CHAR) - line : -1;
	i2 = ft_strchr(line, ' ') ? ft_strchr(line, ' ') - line : -1;
	i3 = ft_strchr(line, '\t') ? ft_strchr(line, '\t') - line : -1;

	if (i1 > -1 && (i2 > -1 || i3 > -1) && (i1 < i2 || i1 < i3))
		return (1);
	return (0);
}

int	set_instruction(t_asm tasm, int fd, int nb_line)
{
	int		i;
	int		j;
	int		id_instruction;
	int		count;
	int		cursor;
	int		instruction_cursor;
	int		is_label;

	i = 2;
	cursor = -1;
	// printf("set_label_adresse\n");
	if (!set_label_adresse(&tasm))
		return (0);
		// printf("set_label_adresse OK\n");
	while (++i < nb_line)
	{
		// if (tasm.asm_tab[i] && tasm.asm_tab[i][0])
			// printf(">  line in set_instruction %s\n", tasm.asm_tab[i]);
		is_label = 0;
		if (tasm.asm_master[i] && tasm.asm_master[i][0] && tasm.asm_master[i][0][0])
		{
			if (ft_strchr(tasm.asm_master[i][0], LABEL_CHAR))
				is_label = 1;
			if (!(id_instruction = set_opcode(tasm, tasm.asm_master[i][is_label], fd, &cursor)))
				return (0);
			instruction_cursor = cursor;
			// printf("acb for instruction ? %s %i\n",tasm.op_tab[id_instruction - 1].name, tasm.op_tab[id_instruction - 1].acb);
			if (tasm.op_tab[id_instruction].acb)
				set_acb(tasm.op_tab[id_instruction], tasm.asm_master[i][1 + is_label], fd, &cursor);
			// printf("cursor write %i\n", cursor);
			// printf(">>>>>>>>>>> CURSOR %i\n", cursor);
			count = -1;
			j = 0;
			while (++count < tasm.op_tab[id_instruction].nb_params)
			{
				//  printf("WHILE instruction_cursor %i %s \n", instruction_cursor, tasm.asm_master[i][1 + is_label] + j );
				if (tasm.asm_master[i][1 + is_label][j] == 'r')
					set_register(tasm.asm_master[i][1 + is_label] + j + 1, fd, &cursor);
				else if (tasm.asm_master[i][1 + is_label][j] == '%')
					set_direct(tasm, tasm.op_tab[id_instruction], tasm.asm_master[i][1  + is_label] + j + 1, fd, &cursor, instruction_cursor);
				else
					set_indirect(tasm, tasm.asm_master[i][1 + is_label] + j, fd, &cursor, instruction_cursor);
				// printf("WHILE end\n");
				// ft_putstr(tasm.asm_master[i][1 + is_label] + j);
				// ft_putstr("\n");
				while (tasm.asm_master[i][1 + is_label][j] && tasm.asm_master[i][1 + is_label][j] != SEPARATOR_CHAR)
					j++;
				j++;
			}
		}
	}
	return (1);
}
