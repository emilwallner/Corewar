/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/22 15:57:01 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	free_and_return(char *file, t_asm tasm, int free_tab, int ret)
{
	int	i;
	int	j;

	free(file);
	if (free_tab && tasm.asm_tab)
	{
		i = -1;
		while (tasm.asm_tab[++i])
			free(tasm.asm_tab[i]);
		free(tasm.asm_tab);
	}
	if (free_tab && tasm.asm_tab)
	{
		i = -1;
		while (tasm.asm_master[++i])
		{
			j = -1;
			if (i < 2)
				free(tasm.asm_master[i][0]);
			while (i > 1 && tasm.asm_master[i][++j] != NULL)
				free(tasm.asm_master[i][j]);
			free(tasm.asm_master[i]);
		}
		free(tasm.asm_master);
	}
	if (tasm.labels)
	{
		i = -1;
		while (++i < tasm.nb_labels)
			free(tasm.labels[i].label);
		free(tasm.labels);
	}
	if (!ret)
		ft_putstr("Error\n");
		// while (1);
		// sleep(2);
	return (ret);
}

int			check_asm_header(void)
{
	if (ft_strchr(LABEL_CHARS, '\n') || ft_strchr(CMD_CHARS, '\n') ||
		ft_strchr(NAME_CMD_STRING, '\n') || ft_strchr(COMMENT_CMD_STRING, '\n')
		|| ft_strchr(COMMENT_CHARS, '\n'))
		return (0);
	if (COMMENT_CHAR == '\n' || LABEL_CHAR == '\n' || DIRECT_CHAR == '\n' ||
		SEPARATOR_CHAR == '\n' || COMMENT_CHAR == ' ' || LABEL_CHAR == ' ' ||
		DIRECT_CHAR == ' ' || SEPARATOR_CHAR == ' ')
		return (0);
	if (ft_strchr(LABEL_CHARS, LABEL_CHAR) ||
		ft_strchr(LABEL_CHARS, SEPARATOR_CHAR) ||
		ft_strchr(LABEL_CHARS, COMMENT_CHAR) ||
		ft_strchr(LABEL_CHARS, DIRECT_CHAR))
		return (0);
	if (ft_strchr(COMMENT_CHARS, LABEL_CHAR) ||
		ft_strchr(COMMENT_CHARS, SEPARATOR_CHAR) ||
		ft_strchr(COMMENT_CHARS, COMMENT_CHAR) ||
		ft_strchr(COMMENT_CHARS, DIRECT_CHAR))
		return (0);
	if (ft_strchr(CMD_CHARS, '"'))
		return (0);
	if (COREWAR_EXEC_MAGIC > 0xffffffff)
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	int		i;
	char	*file;
	t_asm	tasm;
	t_read	tread;
	t_header	header;
	int		fd;

	// ft_putstr("OK -2\n");
	if (ac == 1 || !check_asm_header())
		return (0);
	// ft_putstr("HEADER OK");
	i = 0;
	file = NULL;
	tasm.asm_tab = NULL;
	tasm.asm_master = NULL;
	while (++i < ac)
	{
		// ft_putstr("OK -1\n");
		if (ft_strlen(av[i]) < 3 || av[i][ft_strlen(av[i]) - 1] != 's' || av[i][ft_strlen(av[i]) - 2] != '.')
			return (0);
		// ft_putstr("OK 0\n");
		if (!(fd = get_counts(av[i], &tread)) || !tread.nb_char || !tread.nb_line)
			return (0);
		// ft_putstr("OK 1\n");
		if (!(file = ft_strnew(tread.nb_char + 1)))
			return (0);
		if (!(get_asm(fd, file, &tread)))
			return (free_and_return(file, tasm, 0, 0));
		// ft_putstr("OK 2\n");
		tasm.asm_tab = NULL;
		if (!(tasm.asm_tab = ft_memalloc(sizeof(char*) * (tread.nb_line + 1))))
			return (0);
		// ft_putstr("OK 3\n");
		if (split_asm(tasm.asm_tab, file, tread.nb_line) <= 0)
			return (free_and_return(file, tasm, 1, 0));
		if (!(tasm.asm_master = ft_memalloc(sizeof(char**) * (tread.nb_line + 1))))
			return (0);
		if (split_line(tasm.asm_master, &tasm) <= 0)
			return (free_and_return(file, tasm, 1, 0));
		tasm.labels = NULL;
		// ft_putstr("OK 4\n");

		set_op_tab(&tasm);
		count_label(&tasm);
		// ft_putstr("OK 5\n");
		if (!(tasm.labels = ft_memalloc(sizeof(t_label) * (tasm.nb_labels))))
			return (free_and_return(file, tasm, 1, 0));
		// ft_putstr("OK 6\n");
		if (fill_label_tab(&tasm) == 0)
			return (0);
		// ft_putstr("OK 7 \n");
		// to change in check file
		if (check_file(&tasm, &header) == 0)
			return (free_and_return(file, tasm, 1, 0));
		// ft_putstr("OK 8\n");
	}
	// ft_putstr("OK 9\n");
	// ft_putstr("OK 10\n");
	set_hexa(tasm, av[1], tread.nb_line, header);
	// ft_putstr("OK END\n");
	return (free_and_return(file, tasm, 1, 1));
}
