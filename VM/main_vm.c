/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/17 14:16:16 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int ac, char **av)
{
	int		i;
	char	*file;
	t_asm	tasm;
	t_read	tread;

	if (ac == 1 || ac > MAX_PLAYERS)
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
		if (check_instructions(&tasm) == 0)
			return (free_and_return(file, tasm.asm_tab, 1, 0));
	}
	return (free_and_return(file, tasm.asm_tab, 1, 1));
}
