/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:48:14 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/22 18:31:05 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	if_instruction(t_asm *tasm, int *i, int *count, int is_label)
{
	int j;
	int	id_instruct;
	int	param;

	if (!(id_instruct = get_id_by_name(tasm, tasm->asm_master[*i][is_label])))
		return (0);
	if (tasm->op_tab[id_instruct].acb)
		(*count)++;
	j = 0;
	param = -1;
	while (++param < tasm->op_tab[id_instruct].nb_params)
	{
		if (tasm->asm_master[*i][1 + is_label][j] == 'r')
			*count += 1;
		else if (tasm->asm_master[*i][1 + is_label][j] == '%')
			*count = tasm->op_tab[id_instruct].label_size ?
			*count + 2 : *count + 4;
		else
			*count += 2;
		while (tasm->asm_master[*i][1 + is_label][j] &&
			tasm->asm_master[*i][1 + is_label][j] != SEPARATOR_CHAR)
			j++;
		j++;
	}
	return (1);
}

static int	if_no_instruction(t_asm *tasm, int *i, int *count, int *current)
{
	int	is_label;

	is_label = 0;
	if (tasm->asm_master[*i][0] && tasm->asm_master[*i][0][0] &&
		tasm->asm_master[*i][0][0] == COMMENT_CHAR)
		;
	else if (!tasm->asm_master[*i][0] || !tasm->asm_master[*i][0][0])
		is_label = 0;
	else if (tasm->asm_master[*i][0] &&
		ft_strchr(tasm->asm_master[*i][0], LABEL_CHAR))
	{
		is_label = 1;
		if ((*current = get_tlabel_by_index(tasm, *i)) > -1)
			tasm->labels[*current].first_byte = *count;
	}
	return (is_label);
}

int			set_label_adresse(t_asm *tasm)
{
	int	count;
	int	i;
	int	current_label;
	int	is_label;

	count = 0;
	i = 1;
	current_label = -1;
	while (tasm->asm_master[++i] != NULL)
	{
		is_label = 0;
		is_label = if_no_instruction(tasm, &i, &count, &current_label);
		if (tasm->asm_master[i][is_label] && tasm->asm_master[i][is_label][0] &&
			tasm->asm_master[i][is_label][0] != COMMENT_CHAR)
		{
			count++;
			if (!if_instruction(tasm, &i, &count, is_label))
				return (0);
		}
	}
	return (count);
}
