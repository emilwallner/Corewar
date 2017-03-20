/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:21:54 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/20 17:33:11 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_file_name(char *str, t_header *header)
{
	int i;
	int	len;

	len = ft_strlen(str);
	if (ft_strnstr(str, NAME_CMD_STRING, 5) == NULL)
	{
		// ft_putstr("NNN\n");
		return (0);
	}
	if (str[5] != ' ' || str[6] != '"' || str[len - 1] != '"')
	{
		// ft_putstr("MMM\n");
		// ft_putchar(str[5]);
		// ft_putchar(str[6]);
		// ft_putchar(str[len - 1]);
		return (0);
	}
	if (len - 8 > PROG_NAME_LENGTH)
	{
		// ft_putstr("VVV\n");

		return (0);
	}
	i = 7;
	// ft_putstr("UUU\n");
	while (i < len - 1)
	{
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL)
			return (0);
		header->prog_name[i - 7] = str[i];
		i++;
	}
	return (1);
}

int	check_file_comment(char *str, t_header *header)
{
	int i;
	int	len;

	len = ft_strlen(str);
	if (ft_strnstr(str, COMMENT_CMD_STRING, 8) == NULL)
	{
		// ft_putstr(str);
		// ft_putstr("FFF\n");
		// ft_putstr(COMMENT_CMD_STRING);

		return (0);
	}
	if (str[8] != ' ' || str[9] != '"' || str[len - 1] != '"')
	{
		// ft_putstr("GGG\n");
		return (0);
	}
	if (len - 11 > COMMENT_LENGTH)
	{
		// ft_putstr("HHH\n");
		return (0);
	}
	i = 10;
	while (i < len - 1)
	{
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL)
		{
			// ft_putchar(str[i]);
			// ft_putstr("JJJ\n");
			return (0);
		}
		header->prog_name[i - 10] = str[i];
		i++;
	}
	return (1);
}

int	check_file(t_asm *tasm, t_header *header)
{
	ft_bzero(header, sizeof(t_header));
	if (!tasm->asm_master[0][0] || check_file_name(tasm->asm_master[0][0], header) == 0)
	{
		// ft_putstr(tasm->asm_master[0][0]);
		// ft_putstr("LLL\n");

		return (0);
	}
	if (!tasm->asm_master[1][0] || check_file_comment(tasm->asm_master[1][0], header) == 0)
	{
		// ft_putstr("KKK\n");

		return (0);
	}
	// ft_putstr("PPP\n");
	if (!tasm->asm_master[2] || check_instructions(tasm) == 0)
	{
		// ft_putstr("QQQ\n");

		return (0);
	}
	return (1);
}
