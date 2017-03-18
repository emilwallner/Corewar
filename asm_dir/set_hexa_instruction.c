/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:45:44 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/18 18:19:17 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	g_opcode_hex[17] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

int	set_opcode(char *line, int fd)
{
	int		i;
	int		id;
	char	*name;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	if (!(name = ft_strsub(line, 0, i)))
		return (0);
	if (!(id = get_id_by_name(name)))
	{
		free(name);
		return (0);
	}
	ft_putchar_fd(g_opcode_hex[id], fd);
	free(name);
	return (id);
}

void	set_acb(t_op top, char *line, int fd)
{
	unsigned char	acb;
	int				i;
	int				j;

	i = -1;
	acb = 0;
	j = 0;
	while (++i < top.nb_params)
	{
		if (line[0] == 'r')
			acb = acb + (T_REG << ((top.nb_params - i) * 2 + 1));
		else if (line[0] == '%')
			acb = acb + (T_DIR << ((top.nb_params - i) * 2 + 1));
		else
			acb = acb + (T_IND << ((top.nb_params - i) * 2 + 1));
		// printf("racb %i\n", acb);
	}
	ft_putchar_fd(acb, fd);
// ft_putnbr_base(acb, 2);
	// printf("acb %i\n", acb);
}

int	set_instruction(t_asm tasm, int fd, int nb_line)
{
	int	i;
	int	j;
	int	id_instruction;
	i = 2;
	while (++i < nb_line)
	{
		// printf(">  line in set_instruction %s\n", tasm.asm_tab[i]);
		if (tasm.asm_tab[i] && tasm.asm_tab[i][0])
		{
			j = 0;
			while (ft_strchr(LABEL_CHARS, tasm.asm_tab[i][j]))
				j++;
			j += 1;
			while (tasm.asm_tab[i][j] == ' ' || tasm.asm_tab[i][j] == '\t')
				j++;
			if (!(id_instruction = set_opcode(tasm.asm_tab[i] + j, fd)))
				return (0);
			while (!(tasm.asm_tab[i][j] == ' ' || tasm.asm_tab[i][j] == '\t'))
				j++;
			while (tasm.asm_tab[i][j] == ' ' || tasm.asm_tab[i][j] == '\t')
				j++;
			// printf("acb for instruction ? %s %i\n",tasm.op_tab[id_instruction - 1].name, tasm.op_tab[id_instruction - 1].acb);

			if (tasm.op_tab[id_instruction - 1].acb)
				set_acb(tasm.op_tab[id_instruction], tasm.asm_tab[i] + j, fd);
		}
	}
	return (1);
}
