/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/04/26 19:23:05 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_asm_header(void)
{
	if (ft_strchr(LABEL_CHARS, '\n') || ft_strchr(CMD_CHARS, '\n') ||
		ft_strchr(NAME_CMD_STRING, '\n') || ft_strchr(COMMENT_CMD_STRING, '\n')
		|| ft_strchr(COMMENT_CHARS, '\n') || ft_strchr(LABEL_CHARS, ' '))
		return (error_header(0));
	if (COMMENT_CHAR == '\n' || LABEL_CHAR == '\n' || DIRECT_CHAR == '\n' ||
		SEPARATOR_CHAR == '\n' || COMMENT_CHAR == ' ' || LABEL_CHAR == ' ' ||
		DIRECT_CHAR == ' ' || SEPARATOR_CHAR == ' ')
		return (error_header(0));
	if (ft_strchr(LABEL_CHARS, LABEL_CHAR) ||
		ft_strchr(LABEL_CHARS, SEPARATOR_CHAR) ||
		ft_strchr(LABEL_CHARS, COMMENT_CHAR) ||
		ft_strchr(LABEL_CHARS, DIRECT_CHAR))
		return (error_header(0));
	if (ft_strchr(COMMENT_CHARS, LABEL_CHAR) ||
		ft_strchr(COMMENT_CHARS, SEPARATOR_CHAR) ||
		ft_strchr(COMMENT_CHARS, COMMENT_CHAR) ||
		ft_strchr(COMMENT_CHARS, DIRECT_CHAR))
		return (error_header(0));
	if (ft_strchr(CMD_CHARS, '"'))
		return (error_header(0));
	if (COREWAR_EXEC_MAGIC > 0xffffffff)
		return (error_header(1));
	return (1);
}

int			set_asm_master(t_asm *tasm, char *file, t_read *tread, char *str)
{
	int			fd;

	tasm->asm_tab = NULL;
	tasm->asm_master = NULL;
	if ((fd = get_counts(str, tread)) < 0 || !tread->nb_char || !tread->nb_line)
		return (eol(12));
	if (!(file = ft_strnew(tread->nb_char + 1)))
		return (0);
	if ((get_asm(fd, file, tread)) == -1)
		return (free_and_return(tasm, 0));
	tasm->asm_tab = NULL;
	if (!(tasm->asm_tab = ft_memalloc(sizeof(char*) * (tread->nb_line + 1))))
		return (0);
	if (split_asm(tasm->asm_tab, file, tread->nb_line) <= 0)
		return (free_and_return(tasm, 0));
	if (!(tasm->asm_master =
		ft_memalloc(sizeof(char**) * (tread->nb_line + 1))))
		return (0);
	if (split_line(tasm->asm_master, tasm) <= 0)
		return (free_and_return(tasm, 0));
	free(file);
	return (1);
}

int			call_assembly(char *str)
{
	char		*file;
	t_asm		tasm;
	t_read		tread;
	t_header	header;

	file = NULL;
	if (!set_asm_master(&tasm, file, &tread, str))
		return (0);
	tasm.labels = NULL;
	set_op_tab(&tasm);
	count_label(&tasm);
	if (!(tasm.labels = ft_memalloc(sizeof(t_label) * (tasm.nb_labels))))
		return (free_and_return(&tasm, 0));
	if (fill_label_tab(&tasm) == 0)
		return (0);
	if (check_file(&tasm, &header) == 0)
		return (free_and_return(&tasm, 0));
	set_hexa(tasm, str, tread.nb_line, header);
	free_and_return(&tasm, 1);
	return (1);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac == 1 || !check_asm_header())
		return (eol(14));
	i = 0;
	while (++i < ac)
	{
		ft_putstr("File |");
		ft_putstr(av[i]);
		ft_putstr("| ");
		if (ft_strlen(av[i]) < 3 || av[i][ft_strlen(av[i]) - 1] != 's' ||
		av[i][ft_strlen(av[i]) - 2] != '.')
			error_header(2);
		else
			call_assembly(av[i]);
	}
	return (1);
}
