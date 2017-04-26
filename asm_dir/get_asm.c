/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_asm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:31:37 by mhaziza           #+#    #+#             */
/*   Updated: 2017/04/26 16:33:32 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	counts_char_line(char *buff, t_read *tread)
{
	int	i;

	i = -1;
	while (buff[++i])
		if (buff[i] == '\n')
			tread->nb_line += 1;
	tread->nb_char += i;
}

int			get_counts(char *file_name, t_read *tread)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		fd;

	tread->nb_char = 0;
	tread->nb_line = 0;
	buff[0] = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		counts_char_line(buff, tread);
	}
	if (ret > -1)
		lseek(fd, 0, SEEK_SET);
	if (!tread->nb_char || tread->nb_line < 4)
		return (-1);
	return (fd);
}

int			get_asm(int fd, char *file, t_read *tread)
{
	if (read(fd, file, tread->nb_char) == -1)
		return (0);
	file[tread->nb_char] = '\0';
	if (close(fd) == -1)
		return (0);
	return (1);
}

int			split_asm(char **asm_tab, char *file, int nb)
{
	int	i;
	int	line;
	int	cursor;

	i = -1;
	line = -1;
	asm_tab[0] = NULL;
	while (++line < nb && ++i >= 0)
	{
		cursor = 0;
		while (file[i + cursor] && file[i + cursor] != '\n')
			cursor++;
		if (!(asm_tab[line] = ft_strnew(cursor + 1)))
			return (0);
		cursor = 0;
		while (file[i] && file[i] != '\n')
		{
			asm_tab[line][cursor] = file[i];
			cursor++;
			i++;
		}
		asm_tab[line][cursor] = '\0';
	}
	asm_tab[line] = NULL;
	return (1);
}
