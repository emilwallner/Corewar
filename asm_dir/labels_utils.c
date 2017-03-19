/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:36:16 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/19 16:27:46 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	existing_label(char *label, t_label *labels, int nb)
{
	int	i;

	i = 0;
	while (i < nb && (labels[i]).index > 0)
	{
		if (ft_strcmp((labels[i]).label, label) == 0)
			return (1);
		i++;
	}
	// ft_putstr("XXXX\n");
	return (0);
}

int	check_label(t_instruction *line, t_asm *tasm, char *str)
{
	int	label_end;

	// ft_putstr("RRR\n");
	label_end = ft_strchr(str, LABEL_CHAR) - str + 1;
	line->label = ft_strsub(str, 0, label_end - 1);
	if (!existing_label(line->label, tasm->labels, tasm->nb_labels))
	{
		// ft_putstr("ZZZ\n");
		// printf("label = %s, nb = %d\n", line->label, tasm->nb_labels);
		return (-1);
	}
	return (label_end);
}

int	count_label(t_asm *tasm)
{
	int	i;

	i = 2;
	while (tasm->asm_tab[i] != NULL)
	{
		if (check_valid_label(tasm->asm_tab[i]) == 1)
			tasm->nb_labels++;
		i++;
	}
	return (1);
}
