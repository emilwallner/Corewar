/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/15 17:55:09 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_counts(char *buff, t_read *tread)
{
	int	i;

	i = -1;
	while (buff[++i])
		if (buff[i] == '\n')
			tread->nb_line += 1;
	tread->nb_char += i;
}

int		get_asm(char *file_name, char **file)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		fd;
	t_read	tread;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	tread.nb_line = 0;
	tread.nb_char = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		get_counts(buff, &tread);
	}
	if (close(fd) == -1)
		return (0);
	if (ret == -1)
		return (0);
	if (!tread.nb_char || tread.nb_line < 4)
		return (0);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	if (!(*file = ft_strnew(tread.nb_char + 1)))
		return (0);
	if (read(fd, *file, tread.nb_char) == -1)
		return (0);
	(*file)[tread.nb_char] = '\0';
	if (close(fd) == -1)
		return (0);
	return (tread.nb_line);
}

int	split_asm(char **asm_tab, char *file, int nb)
{
	int		i;
	int		line;
	int cursor;

	ft_putstr("split_asm IN\n");
	i = 0;
	line = -1;
	asm_tab[0] = NULL;
	while (++line < nb)
	{
		ft_putstr("split_asm\n");
		cursor = 0;
		while (file[i + cursor] && file[i + cursor] != '\n')
			cursor++;
			ft_putstr("split_asm\n");
			ft_putnbr(cursor);
		if (!(asm_tab[line] = ft_strnew(cursor + 1)))
		{ft_putstr("split_asm ERROR\n");	return (0);}
		cursor = 0;
		ft_putstr("split_asm\n");
		while (file[i] && file[i] != '\n')
		{
			asm_tab[line][cursor] = file[i];
			cursor++;
			i++;
		}
		ft_putstr("split_asm\n");
		asm_tab[line][cursor] = '\0';
		i++;
	}
	asm_tab[line] = NULL;
	ft_putstr("split_asm OUT\n");
	return (1);
}

int		main(int ac, char **av)
{
	int		i;
	int		nb_line;
	char	*file;
	char	**asm_tab;

	if (ac == 1)
		return(0);
	i = 0;
	file = NULL;
	while (++i < ac)
	{
		if (!(nb_line = get_asm(av[i], &file)) || !file)
		{
			free(file);
			while(1);
			return (0);
		}
		asm_tab = NULL;
		if (!(asm_tab = ft_memalloc(sizeof(char*) * (nb_line + 1))))
			return (-1);
		if (split_asm(asm_tab, file, nb_line) <= 0)
		{
			free(file);
			i = 0;
			while (asm_tab[i])
				free(asm_tab[i]);
			free(asm_tab);
			while(1);
			return (0);
		}
		ft_putstr("fin\n");
	}
	free(file);
	i = -1;
	while (asm_tab[++i])
		free(asm_tab[i]);
	free(asm_tab);
	return (1);
}
