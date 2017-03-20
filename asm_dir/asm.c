/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/20 14:45:21 by tlenglin         ###   ########.fr       */
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

int			main(int ac, char **av)
{
	int		i;
	char	*file;
	t_asm	tasm;
	t_read	tread;
	t_header	header;

	if (ac == 1)
		return (0);
	i = 0;
	file = NULL;
	while (++i < ac)
	{
		ft_putstr("OK 0\n");
		if (!(get_counts(av[i], &tread)) || !tread.nb_char || !tread.nb_line)
			return (0);
		ft_putstr("OK 1\n");
		if (!(file = ft_strnew(tread.nb_char + 1)))
			return (0);
		if (!(get_asm(av[i], file, &tread)))
			return (free_and_return(file, NULL, 0, 0));
		ft_putstr("OK 2\n");
		tasm.asm_tab = NULL;
		if (!(tasm.asm_tab = ft_memalloc(sizeof(char*) * (tread.nb_line + 1))))
			return (0);
		ft_putstr("OK 3\n");
		if (split_asm(tasm.asm_tab, file, tread.nb_line) <= 0)
			return (free_and_return(file, tasm.asm_tab, 1, 0));
		if (!(tasm.asm_master = ft_memalloc(sizeof(char**) * (tread.nb_line + 1))))
			return (0);
		if (split_line(tasm.asm_master, &tasm) <= 0)
			return (free_and_return(file, tasm.asm_tab, 1, 0));
		tasm.labels = NULL;
		ft_putstr("OK 4\n");

		set_op_tab(&tasm);
		count_label(&tasm);
		ft_putstr("OK 5\n");
		if (!(tasm.labels = ft_memalloc(sizeof(t_label) * (tasm.nb_labels))))
			return (free_and_return(file, tasm.asm_tab, 1, 0));
		ft_putstr("OK 6\n");
		if (fill_label_tab(&tasm) == 0)
			return (0);
		ft_putstr("OK 7 \n");
		// to change in check file
		if (check_file(&tasm, &header) == 0)
			return (free_and_return(file, tasm.asm_tab, 1, 0));
		ft_putstr("OK 8\n");
	}
	ft_putstr("OK 9\n");
	ft_putstr("OK 10\n");
	set_hexa(tasm, av[1], tread.nb_line);
	ft_putstr("OK END\n");
	return (free_and_return(file, tasm.asm_tab, 1, 1));
}
