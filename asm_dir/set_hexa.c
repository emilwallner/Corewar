/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:45:01 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/18 22:08:59 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	create_hexa(char *str)
{
	int	fd;
	char	*name;
	int		i;

	i = 0;
	if ((name = ft_strnew(ft_strlen(str) + 3)) == NULL)
		return (0);
	while (str[i + 1])
	{
		name[i] = str[i];
		i++;
	}
	name[i] = 'c';
	name[++i] = 'o';
	name[++i] = 'r';
	name[++i] = '\0';
	if ((fd = open(name, O_RDWR | O_CREAT, 0666)) == -1)
		return (-1);
	// ft_putnbr(fd);
	return (fd);
}

int	set_filename(t_asm tasm, int fd)
{
	int	i;
	// char buff[10];

	ft_putchar_fd(0x00, fd);
	ft_putchar_fd(0xea, fd);
	ft_putchar_fd(0x83, fd);
	ft_putchar_fd(0xf3, fd);
	// ft_putnbr(read(fd, buff, 5));
	i = 6;
	while (tasm.asm_tab[0][++i] != '"')
	{
		ft_putchar_fd(tasm.asm_tab[0][i], fd);
		// ft_putchar(tasm.asm_tab[0][i]);
	}
	while (++i < PROG_NAME_LENGTH + 8)
		ft_putchar_fd(0x0, fd);

	return (1);
}

int	set_comment(t_asm tasm, int fd)
{
	int	i;
	// char buff[10];
	i = -1;
	while (++i < 7)
		ft_putchar_fd(0x00, fd);
	ft_putchar_fd(0x3f, fd);
	// ft_putnbr(read(fd, buff, 5));
	i = 9;
	while (tasm.asm_tab[1][++i] != '"')
	{
		ft_putchar_fd(tasm.asm_tab[1][i], fd);
		// ft_putchar(tasm.asm_tab[1][i]);
	}
	while (++i < COMMENT_LENGTH + 15)
		ft_putchar_fd(0x0, fd);

	return (1);
}

int	set_hexa(t_asm tasm, char *str, int nb_line)
{
	int fd;

	// ft_putstr(tasm.asm_tab[0]);
	if ((fd = create_hexa(str)) == -1)
		return (0);
	if (set_filename(tasm, fd) == 0)
		return (0);
	ft_putstr("set_filename OK\n");
	if (set_comment(tasm, fd) == 0)
		return (0);
	ft_putstr("set_comment OK\n");
	if (set_instruction(tasm, fd, nb_line) == 0)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}
