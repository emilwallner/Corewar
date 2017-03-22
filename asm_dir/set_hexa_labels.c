/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:48:14 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/22 17:14:02 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int set_label_adresse(t_asm *tasm)
{
	int	count;
	int	i;
	int j;
	int	current_label;
	int in_label;
	int	param;
	int	id_instruction;
	int	is_label;

	count = 0;
	i = 1;
	in_label = 0;
	current_label = -1;
	while (tasm->asm_master[++i] != NULL)
	{
		is_label = 0;
		j = 0;
		if (tasm->asm_master[i][0] &&tasm->asm_master[i][0][0] && tasm->asm_master[i][0][0] == COMMENT_CHAR)
			;
		else if (!tasm->asm_master[i][0] || !tasm->asm_master[i][0][0])
		{
			in_label = 0;
			is_label = 0;
		}
		else if (tasm->asm_master[i][0] && ft_strchr(tasm->asm_master[i][0], LABEL_CHAR))
		{
			in_label = 1;
			is_label = 1;
			if ((current_label = get_tlabel_by_index(tasm, i)) > -1)
				tasm->labels[current_label].first_byte = count;
		}
		if (tasm->asm_master[i][is_label] && tasm->asm_master[i][is_label][0] && tasm->asm_master[i][is_label][0] != COMMENT_CHAR)
		{
			count++;
			if (!(id_instruction = get_id_by_name(tasm, tasm->asm_master[i][is_label])))
				return (0);
			if (tasm->op_tab[id_instruction].acb)
				count++;
			j = 0;
			param = -1;
			while (++param < tasm->op_tab[id_instruction].nb_params)
			{
				if (tasm->asm_master[i][1 + is_label][j] == 'r')
					count += 1;
				else if (tasm->asm_master[i][1 + is_label][j] == '%')
					count = tasm->op_tab[id_instruction].label_size ? count + 2 : count + 4;
				else
					count += 2;
				while (tasm->asm_master[i][1 + is_label][j] && tasm->asm_master[i][1 + is_label][j] != SEPARATOR_CHAR)
					j++;
				j++;
			}
		}
	}
	return (count);
}
