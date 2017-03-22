/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:45:01 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/22 19:38:56 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	create_hexa(char *str)
{
	int		fd;
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
	free(name);
	return (fd);
}

static int	set_filename(int fd, t_header header)
{
	int		i;
	long	nb;
	int		count;

	count = 0;
	nb = COREWAR_EXEC_MAGIC;
	while (nb != 0)
	{
		nb = nb / 256;
		count++;
	}
	while (4 - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	puthexa_fd(COREWAR_EXEC_MAGIC, fd);
	i = -1;
	while (header.prog_name[++i])
		ft_putchar_fd(header.prog_name[i], fd);
	while (++i < PROG_NAME_LENGTH + 1)
		ft_putchar_fd(0x0, fd);
	return (1);
}

static int	set_comment(int fd, t_header header, int nb_bytes)
{
	int		i;
	int		count;
	long	nb;

	i = -1;
	nb = nb_bytes;
	count = 0;
	while (nb != 0)
	{
		nb = nb / 256;
		count++;
	}
	while (8 - count)
	{
		ft_putchar_fd(0x0, fd);
		count++;
	}
	puthexa_fd(nb_bytes, fd);
	i = -1;
	while (header.comment[++i])
		ft_putchar_fd(header.comment[i], fd);
	while (++i < COMMENT_LENGTH + 5)
		ft_putchar_fd(0x0, fd);
	return (1);
}

int			set_hexa(t_asm tasm, char *str, int nb_line, t_header header)
{
	int fd;
	int count;

	if ((fd = create_hexa(str)) == -1)
		return (0);
	if (!(count = set_label_adresse(&tasm)) || count > CHAMP_MAX_SIZE)
		return (0);
	if (set_filename(fd, header) == 0)
		return (0);
	if (set_comment(fd, header, count) == 0)
		return (0);
	if (set_instruction(tasm, fd, nb_line) == 0)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}
