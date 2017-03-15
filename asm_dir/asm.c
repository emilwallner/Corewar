/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/15 18:41:28 by mhaziza          ###   ########.fr       */
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
	return (ret);
}

int			main(int ac, char **av)
{
	int		i;
	char	*file;
	char	**asm_tab;
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
			return (free_and_return(file, asm_tab, 0, 0));
		asm_tab = NULL;
		if (!(asm_tab = ft_memalloc(sizeof(char*) * (tread.nb_line + 1))))
			return (-1);
		if (split_asm(asm_tab, file, tread.nb_line) <= 0)
			return (free_and_return(file, asm_tab, 1, 0));
	}
	ft_puttab_str(asm_tab);
	return (free_and_return(file, asm_tab, 1, 1));
}
