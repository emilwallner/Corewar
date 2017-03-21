/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:26:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/21 19:31:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	set_register(char *params, int fd, int *cursor)
{
	// printf("REGISTER\n");
	ft_putchar_fd(ft_atoi(params),fd);
	*cursor +=1;
}

void puthexa_fd(long code, int fd)
{
	// printf("puthexa code = %x\n", code);
	if (code >= 16*16)
	{
		puthexa_fd(code / (16 * 16), fd);
		puthexa_fd(code % (16 * 16), fd);
	}
	else
		ft_putchar_fd(code, fd);
}

void	set_direct(t_asm tasm, t_op top, char *params, int fd, int *cursor, int instruction_cursor)
{
	int	i;
	long	nb;
	int	j;
	long code;
	char	*name;

	// printf(">>SET DIRECT PARAM \n   params %s\n instruction_cursor %i\n", params, instruction_cursor);
	i = 0;
	if (params[0] == LABEL_CHAR)
	{
		// printf("in if %s\n", params);
		j = 0;
		while (params[j]  && params[j] != SEPARATOR_CHAR)
			j++;
		// printf("debug j = %i\n", j);
		if (!(name = ft_strsub(params, 1, j - 1)))
			return ;
		//  ft_putstr(name);
		code = tasm.labels[get_tlabel_by_name(&tasm, name)].first_byte - instruction_cursor;
		free (name);
		// printf("   first_byte %i code label %i\n", tasm.labels[get_tlabel_by_name(&tasm, name)].first_byte, code);
	}
	else
		code = ft_atoi(params);
	// code = code >= 0 ? code : 65536 + code;
	if (code < 0)
	{	if (top.label_size)
			code += 65536;
		else
			code += 4294967296;}
	i = 1;
	nb = code;
	while (nb / 256)
	{
		// ft_putnbr(nb);
		// ft_putchar(' ');
		// ft_putnbr(i);
		// ft_putchar('\n');
		nb /= 256;
		i++;
	}
	nb = i;
	// printf("nb = %i CODE = %x  top.label_size = %i\n", nb, code, top.label_size);
	i = -1;
	while (++i < 2 + 2 * (1 - top.label_size) - nb)
		ft_putchar_fd(0,fd);
	puthexa_fd(code, fd);
	*cursor = top.label_size ? *cursor + 2 : *cursor + 4;
}

void	set_indirect(t_asm tasm, char *params, int fd, int *cursor, int instruction_cursor)
{
	int	i;
	int	j;
	int code;
	char	*name;

	// printf("   SET INDIRECT PARAM \n   instruction_cursor %i\n", instruction_cursor);
	i = instruction_cursor;
	i = 0;
	if (params[0] == LABEL_CHAR)
	{
		j = 0;
		while (params[j] != SEPARATOR_CHAR)
			j++;
		if (!(name = ft_strsub(params, 1, j - 1)))
			return ;
		code = tasm.labels[get_tlabel_by_name(&tasm, name)].first_byte - instruction_cursor;
		free (name);
		// printf(" get_tlabel_by_name %i NAME %s   first_byte %i code label %i instruction_cursor %i\n", get_tlabel_by_name(&tasm, name), name, tasm.labels[get_tlabel_by_name(&tasm, name)].first_byte, code, instruction_cursor);
	}
	else
		code = ft_atoi(params);
	code = code > 0 ? code : 65536 + code;
	// printf("CODE = %x\n", code);
	ft_putchar_fd(code / 256,fd);
	ft_putchar_fd(code % 256,fd);
	*cursor += 2;
}
