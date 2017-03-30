/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:36:16 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/30 15:20:54 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	count_label(t_asm *tasm)
{
	int	i;

	i = 2;
	while (tasm->asm_master[i] != NULL)
	{
		if (tasm->asm_master[i][0] &&
			check_valid_label(tasm->asm_master[i][0]) == 1)
			tasm->nb_labels++;
		i++;
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
		if (!ft_strcmp(tasm->labels[i].label, name))
			return (i);
	}
	return (-1);
}

int	fill_label_tab(t_asm *tasm)
{
	int i;
	int j;

	i = 2;
	while (tasm->asm_master[i] != NULL)
	{
		if (tasm->asm_master[i][0] &&
			check_valid_label(tasm->asm_master[i][0]) == 1)
		{
			j = 0;
			while (j < tasm->nb_labels && (tasm->labels[j]).index > 0)
			{
				if (!ft_strcmp((tasm->labels[j]).label, tasm->asm_master[i][0]))
					return (0);
				j++;
			}
			tasm->labels[j].index = i;
			if (!(tasm->labels[j].label = ft_strsub(tasm->asm_master[i][0], 0,
				ft_strlen(tasm->asm_master[i][0]) - 1)))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_label(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr(LABEL_CHARS, str[0]) == NULL || ft_strchr(str, ':') == NULL)
		return (0);
	while (str[i] != ':')
	{
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}
