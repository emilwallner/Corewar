/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/17 17:00:57 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


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

int			main(int ac, char **av)
{
	int		i;
	(void)ac;
	char	*file;
	t_asm	tasm;
	t_read	tread;

	printf("YO\n");
	// if (ac == 1 || ac > MAX_PLAYERS)
	// 	return (0);
	i = 0;
	file = NULL;
	while (++i < 10)
	{
		// if (!(get_counts(av[i], &tread)) || !tread.nb_char || !tread.nb_line)
		// 	return (0);
		tread.nb_char = 1000000;
		printf("YO\n");
		if (!(file = ft_strnew(tread.nb_char + 1)))
			return (0);
		printf("YO\n");
		if (!(get_asm(av[i], file, &tread)))
			return (free_and_return(file, NULL, 0, 0));
		tasm.asm_tab = NULL;
		if (!(tasm.asm_tab = ft_memalloc(sizeof(char*) * (tread.nb_line + 1))))
			return (0);
		if (split_asm(tasm.asm_tab, file, tread.nb_line) <= 0)
			return (free_and_return(file, tasm.asm_tab, 1, 0));
		tasm.labels = NULL;
		//count_label(&tasm);
		//if (!(tasm.labels = ft_memalloc(sizeof(t_label) * (tasm.nb_labels))))
		//	return (free_and_return(file, tasm.asm_tab, 1, 0));
		//if (check_instructions(&tasm) == 0)
		//	return (free_and_return(file, tasm.asm_tab, 1, 0));
	}
	return (free_and_return(file, tasm.asm_tab, 1, 1));
}
