/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:45:01 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/17 18:16:31 by tlenglin         ###   ########.fr       */
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
	if ((fd = open(name, O_RDWR | O_CREAT)) == -1)
		return (-1);
	// ft_putnbr(fd);
	return (fd);
}

int	set_filename(t_asm tasm, int fd)
{
	int	i;
// char buff[10];
	ft_putstr_fd("00 ea 83 f3 ", fd);
	// ft_putnbr(read(fd, buff, 5));
	i = 7;
	while (tasm.asm_tab[0][i] != '"')
	{
		ft_putchar_fd(tasm.asm_tab[0][i], fd);
		// if (i % 2)
		ft_putchar_fd(' ', fd);
		ft_putchar(tasm.asm_tab[0][i]);
			ft_putchar('+');
		i++;
	}

	return (1);
}

int	set_hexa(t_asm tasm, char *str)
{
	int fd;

	// ft_putstr(tasm.asm_tab[0]);
	if ((fd = create_hexa(str)) == -1)
		return (0);
	if (set_filename(tasm, fd) == 0)
		return (0);
	// if (set_comment() == 0)
	// 	return (0);
	// if (set_instruction() == 0)
	// 	return (0);
	close(fd);
	return (1);
}
