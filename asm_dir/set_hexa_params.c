/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:26:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/23 15:03:35 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	set_register(char *params, int fd, int *cursor)
{
	ft_putchar_fd(ft_atoi(params), fd);
	(*cursor) += 1;
}

void	puthexa_fd(long code, int fd)
{
	if (code >= 16 * 16)
	{
		puthexa_fd(code / (16 * 16), fd);
		puthexa_fd(code % (16 * 16), fd);
	}
	else
		ft_putchar_fd(code, fd);
}

int		get_code(t_asm tasm, char *params, int instruction_cursor, long *code)
{
	int		j;
	int		id;
	char	*name;

	j = 0;
	while (params[j] && params[j] != SEPARATOR_CHAR)
		j++;
	if (!(name = ft_strsub(params, 1, j - 1)))
		return (0);
	if ((id = get_tlabel_by_name(&tasm, name)) == -1)
		return (0);
	*code = tasm.labels[id].first_byte - instruction_cursor;
	free(name);
	return (1);
}

void	set_direct(t_write_params *twp)
{
	int		i;
	long	nb;
	long	code;

	i = 0;
	if (twp->cell[1] != LABEL_CHAR)
		code = twp->top.label_size ? ft_atoi(twp->cell + 1) % BY2 :
		ft_atoi(twp->cell + 1) % BY4;
	else
	{
		if (!get_code(twp->tasm, twp->cell + 1, twp->ins_cursor, &code))
			return ;
	}
	if (code < 0)
		code = twp->top.label_size ? code + BY2 : code + BY4;
	i = 1;
	nb = code;
	while (nb / 256 && i++)
		nb /= 256;
	nb = i;
	i = -1;
	while (++i < 2 + 2 * (1 - twp->top.label_size) - nb)
		ft_putchar_fd(0, twp->fd);
	puthexa_fd(code, twp->fd);
	*twp->cur_cur = twp->top.label_size ? *twp->cur_cur + 2 : *twp->cur_cur + 4;
}

void	set_indirect(t_write_params *twp)
{
	long code;

	if (twp->cell[0] == LABEL_CHAR)
	{
		if (!get_code(twp->tasm, twp->cell, twp->ins_cursor, &code))
			return ;
	}
	else
		code = ft_atoi(twp->cell) % BY2;
	code = code > 0 ? code : BY2 + code;
	ft_putchar_fd(code / 256, twp->fd);
	ft_putchar_fd(code % 256, twp->fd);
	*twp->cur_cur += 2;
}
