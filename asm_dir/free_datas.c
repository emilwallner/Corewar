/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_datas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:59:57 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/31 15:37:09 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_asm_master(t_asm *tasm)
{
	int i;
	int j;

	if (tasm->asm_master)
	{
		i = -1;
		while (tasm->asm_master[++i])
		{
			j = -1;
			if (i < 2)
				free(tasm->asm_master[i][0]);
			while (i > 1 && tasm->asm_master[i][++j] != NULL)
				free(tasm->asm_master[i][j]);
			free(tasm->asm_master[i]);
		}
		free(tasm->asm_master);
	}
}

static void	free_asm_tab(t_asm *tasm)
{
	int i;

	if (tasm->asm_tab)
	{
		i = -1;
		while (tasm->asm_tab[++i])
			free(tasm->asm_tab[i]);
		free(tasm->asm_tab);
	}
}

int			free_and_return(t_asm *tasm, int ret)
{
	int	i;

	free_asm_tab(tasm);
	free_asm_master(tasm);
	if (tasm->labels)
	{
		i = -1;
		while (++i < tasm->nb_labels)
			free(tasm->labels[i].label);
		free(tasm->labels);
	}
	if (ret)
		ft_putstr("\033[32mOK. The .cor file has been generated.\x1b[0m\n");
	return (ret);
}
