/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:26:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/19 22:20:36 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	set_register(char *params, int fd, int *cursor)
{
	// printf("REGISTER\n");
	ft_putchar_fd(ft_atoi(params),fd);
	*cursor +=1;
}

void	set_direct(t_asm tasm, t_op top, char *params, int fd, int *cursor, int instruction_cursor)
{
	int	i;
	int	nb;
	int	j;
	int code;
	char	*name;

	// printf("  SET DIRECT PARAM \n   instruction_cursor %i\n", instruction_cursor);
	i = 0;
	if (params[0] == LABEL_CHAR)
	{
		j = 0;
		while (params[j] != SEPARATOR_CHAR)
			j++;
		if (!(name = ft_strsub(params, 1, j)))
			return ;
		code = tasm.labels[get_tlabel_by_name(&tasm, name)].first_byte - instruction_cursor;
		// printf("   first_byte %i code label %i\n", tasm.labels[get_tlabel_by_name(&tasm, name)].first_byte, code);
	}
	else
		code = ft_atoi(params);
	code = code > 0 ? code : 65536 + code;
	i = 1;
	nb = code;
	while (nb / 16)
	{nb/=16;i++;}
	nb = i;
	// printf("nb = %i CODE = %x\n", nb, code);
	i = -1;
	while (++i < 2 * (1 - top.label_size) - nb / 2)
		ft_putchar_fd(0,fd);
	ft_putchar_fd(code / 256,fd);
	ft_putchar_fd(code % 256,fd);
	*cursor = top.label_size ? *cursor + 2 : *cursor + 4;
}

void	set_indirect(t_asm tasm, char *params, int fd, int *cursor, int instruction_cursor)
{
	int	i;
	int	j;
	int code;
	char	*name;

	// printf("   SET INDIRECT PARAM \n   instruction_cursor %i\n", instruction_cursor);
	i = 0;
	if (params[0] == LABEL_CHAR)
	{
		j = 0;
		while (params[j] != SEPARATOR_CHAR)
			j++;
		if (!(name = ft_strsub(params, 1, j - 1)))
			return ;
		code = tasm.labels[get_tlabel_by_name(&tasm, name)].first_byte - instruction_cursor;
		// printf(" get_tlabel_by_name %i NAME %s   first_byte %i code label %i\n", get_tlabel_by_name(&tasm, name), name, tasm.labels[get_tlabel_by_name(&tasm, name)].first_byte, code);
	}
	else
		code = ft_atoi(params);
	code = code > 0 ? code : 65536 + code;
	// printf("CODE = %x\n", code);
	ft_putchar_fd(code / 256,fd);
	ft_putchar_fd(code % 256,fd);
	*cursor += 2;
}
