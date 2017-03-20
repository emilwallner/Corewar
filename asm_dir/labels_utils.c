/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:36:16 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/20 16:26:44 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// int	existing_label(char *label, t_label *labels, int nb)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < nb && (labels[i]).index > 0)
// 	{
// 		if (ft_strcmp((labels[i]).label, label) == 0)
// 			return (1);
// 		i++;
// 	}
// 	// ft_putstr("XXXX\n");
// 	return (0);
// }
//
// int	check_label(t_instruction *line, t_asm *tasm, char *str)
// {
// 	int	label_end;
//
// 	// ft_putstr("RRR\n");
// 	label_end = ft_strchr(str, LABEL_CHAR) - str + 1;
// 	line->label = ft_strsub(str, 0, label_end - 1);
// 	if (!existing_label(line->label, tasm->labels, tasm->nb_labels))
// 	{
// 		// ft_putstr("ZZZ\n");
// 		// printf("label = %s, nb = %d\n", line->label, tasm->nb_labels);
// 		return (-1);
// 	}
// 	return (label_end);
// }

int	count_label(t_asm *tasm)
{
	int	i;

	i = 2;
	while (tasm->asm_master[i] != NULL)
	{
		ft_putstr("XXX\n");
		if (tasm->asm_master[i][0] && check_valid_label(tasm->asm_master[i][0]) == 1)
			tasm->nb_labels++;
		i++;
		ft_putstr("OOO\n");
	}
	return (1);
}

int	get_tlabel_by_index(t_asm *tasm, int index)
{
	int	i;

	i = -1;
	while (++i < tasm->nb_labels)
	{
		if (tasm->labels[i].index == index)
			return (i);
	}
	return (-1);
}

int	get_tlabel_by_name(t_asm *tasm, char *name)
{
	int	i;

	i = -1;
	while (++i < tasm->nb_labels)
	{
		// printf("tasm->labels[i].label %s name %s\n", tasm->labels[i].label, name);
		if (!ft_strcmp(tasm->labels[i].label, name))
			return (i);
	}
	return (-1);
}
