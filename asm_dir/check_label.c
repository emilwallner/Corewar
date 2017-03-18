/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:01:23 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/18 15:01:50 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
