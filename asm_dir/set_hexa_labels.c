/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:48:14 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/20 18:12:41 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int set_label_adresse(t_asm *tasm)
{
	int	count;
	int	i;
	int j;
	// int	k;
	int	current_label;
	int in_label;
	int	param;
	int	id_instruction;
	// char	*instruction;
	int	is_label;

	// printf("set_label_adresse in\n");
	count = 0;
	i = 1;
	in_label = 0;
	current_label = -1;
	while (tasm->asm_master[++i] != NULL)
	{
		is_label = 0;
		j = 0;
		// printf(">>s LINE %i %s\n", i, tasm->asm_master[i][0]);

		if (!tasm->asm_master[i][0])
		{
			//  printf("EMPTY_LINE current_label %i %s count %i\n", current_label, tasm->labels[current_label].label, count);
			if (current_label >= 0 && in_label)
			{
				//  printf(">>set last_byte\n");
				tasm->labels[current_label].last_byte = count;
				tasm->labels[current_label].byte_size = count - tasm->labels[current_label].first_byte;
			}
			in_label = 0;
			is_label = 0;
		}
		else if (tasm->asm_master[i][0] && ft_strchr(tasm->asm_master[i][0], LABEL_CHAR))
		{
			in_label = 1;
			is_label = 1;
			if ((current_label = get_tlabel_by_index(tasm, i)) > -1)
				tasm->labels[current_label].first_byte = count;
			// j += ft_strlen(tasm->labels[current_label].label) + 1;
			//  printf("\nBEGIN BY LABEL j = %i label = %s\n", j, tasm->labels[current_label].label);
		}
		if (tasm->asm_master[i][0] && tasm->asm_master[i][0][0])
		{
			// printf(">>> NEW LINE count = %i\n", count);

			// printf("NOT EMPTY LINE tasm->asm_tab[i] + j %i %s\n", j, tasm->asm_tab[i] + j);
			count++;
			if (!(id_instruction = get_id_by_name(tasm, tasm->asm_master[i][is_label])))
			{
				// printf("#### instruction %s\n", instruction);
				return (0);
			}
			if (tasm->op_tab[id_instruction].acb)
				count++;
			// printf("INSTRUCTION %s OPCODE %i\n", instruction, id_instruction);
			j = 0;
			param = -1;
			while (++param < tasm->op_tab[id_instruction].nb_params)
			{
				//  printf("LOOP params %s count AV %i ", tasm->asm_master[i][1 + is_label] + j, count);
				if (tasm->asm_master[i][1 + is_label][j] == 'r')
					count += 1;
				else if (tasm->asm_master[i][1 + is_label][j] == '%')
					count = tasm->op_tab[id_instruction].label_size ? count + 2 : count + 4;
				else
					count +=2;
				while (tasm->asm_master[i][1 + is_label][j] && tasm->asm_master[i][1 + is_label][j] != SEPARATOR_CHAR)
					j++;
				j++;
			//  printf("count AP %i\n", count);
			}
		}
	}
// printf("count END  %i\n", count);

	tasm->labels[current_label].last_byte = count;
	tasm->labels[current_label].byte_size = count - tasm->labels[current_label].first_byte;
	i = 0;
	while (i < tasm->nb_labels)
	{
		printf("label %i  :  nom %s, ligne %i, first byte %i, last byte %i, byte size %i\n", i, tasm->labels[i].label, tasm->labels[i].index, tasm->labels[i].first_byte, tasm->labels[i].last_byte, tasm->labels[i].byte_size);
		i++;
	}
	return (1);
}
