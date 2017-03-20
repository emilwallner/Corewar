/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:01:23 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/20 17:25:10 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


// int	check_fill_label(char *label, t_label *labels, int nb, int index)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < nb && (labels[i]).index > 0)
// 	{
// 		if (ft_strcmp((labels[i]).label, label) == 0)
// 			return (0);
// 		i++;
// 	}
// 	labels[i].index = index;
// 	labels[i].label = label;
// 	// ft_putstr("TTT\n");
// 	return (1);
// }
//
// int	set_label(t_asm *tasm, char *str, int iline)
// {
// 	int	label_end;
//
// 	// ft_putstr("WWW\n");
// 	label_end = ft_strchr(str, LABEL_CHAR) - str + 1;
// 	if (!check_fill_label(ft_strsub(str, 0, label_end - 1), tasm->labels, tasm->nb_labels, iline))
// 		return (-1);
// 	return (label_end);
// }

int	fill_label_tab(t_asm *tasm)
{
	int i;
	int j;

	i = 2;
	while (tasm->asm_master[i] != NULL)
	{
		if (tasm->asm_master[i][0] && check_valid_label(tasm->asm_master[i][0]) == 1)
		{
			j = 0;
			while (j < tasm->nb_labels && (tasm->labels[j]).index > 0)
			{
				if (ft_strcmp((tasm->labels[j]).label, tasm->asm_master[i][0]) == 0)
					return (0);
				j++;
			}
			tasm->labels[j].index = i;
			if (!(tasm->labels[j].label = ft_strsub(tasm->asm_master[i][0], 0, ft_strlen(tasm->asm_master[i][0]) - 1)))
				return (0);

			// if (set_label(tasm, tasm->asm_master[i][0], i) == -1)
			// 	return (0);
		}
		i++;
	}
	i = 0;
	ft_putstr("RRRRRRRRRRRRR\n");
	while (i < tasm->nb_labels)
	{
		ft_putstr(tasm->labels[i].label);
		ft_putstr("\n");
		i++;
	}
	return (1);
}

int	check_valid_label(char *str)
{
	int	i;

	i = 0;
	ft_putstr(str);
	ft_putstr("\n");
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
