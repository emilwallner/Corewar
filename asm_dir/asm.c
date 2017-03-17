/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/17 15:24:10 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	free_and_return(char *file, char **asm_tab, int free_tab, int ret)
{
	int	i;

	free(file);
	i = -1;
	while (free_tab && asm_tab[++i])
		free(asm_tab[i]);
	if (free_tab)
		free(asm_tab);
	if (!ret)
		ft_putstr("Error\n");
	return (ret);
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

int			main(int ac, char **av)
{
	int		i;
	char	*file;
	t_asm	tasm;
	t_read	tread;

	if (ac == 1)
		return (0);
	i = 0;
	file = NULL;
	while (++i < ac)
	{
		if (!(get_counts(av[i], &tread)) || !tread.nb_char || !tread.nb_line)
			return (0);
		if (!(file = ft_strnew(tread.nb_char + 1)))
			return (0);
		if (!(get_asm(av[i], file, &tread)))
			return (free_and_return(file, NULL, 0, 0));
		tasm.asm_tab = NULL;
		if (!(tasm.asm_tab = ft_memalloc(sizeof(char*) * (tread.nb_line + 1))))
			return (0);
		if (split_asm(tasm.asm_tab, file, tread.nb_line) <= 0)
			return (free_and_return(file, tasm.asm_tab, 1, 0));
		tasm.labels = NULL;
		count_label(&tasm);
		if (!(tasm.labels = ft_memalloc(sizeof(t_label) * (tasm.nb_labels))))
			return (free_and_return(file, tasm.asm_tab, 1, 0));
		fill_label_tab(&tasm);
		if (check_instructions(&tasm) == 0)
			return (free_and_return(file, tasm.asm_tab, 1, 0));
	}
	ft_putstr("OK\n");
	return (free_and_return(file, tasm.asm_tab, 1, 1));
}
