/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:01:23 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/19 17:37:50 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


int	check_fill_label(char *label, t_label *labels, int nb, int index)
{
	int	i;

	i = 0;
	while (i < nb && (labels[i]).index > 0)
	{
		if (ft_strcmp((labels[i]).label, label) == 0)
			return (0);
		i++;
	}
	labels[i].index = index;
	labels[i].label = label;
	// ft_putstr("TTT\n");
	return (1);
}

int	set_label(t_asm *tasm, char *str, int iline)
{
	int	label_end;

	// ft_putstr("WWW\n");
	label_end = ft_strchr(str, LABEL_CHAR) - str + 1;
	if (!check_fill_label(ft_strsub(str, 0, label_end - 1), tasm->labels, tasm->nb_labels, iline))
		return (-1);
	return (label_end);
}

int	fill_label_tab(t_asm *tasm)
{
	int i;

	i = 2;
	while (tasm->asm_tab[i] != NULL)
	{
		if (check_valid_label(tasm->asm_tab[i]) == 1)
			if (set_label(tasm, tasm->asm_tab[i], i) == -1)
				return (0);
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
