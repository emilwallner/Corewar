/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:21:54 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/21 19:45:11 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_file_name(char *str, t_header *header)
{
	int i;
	int	len;
	int	j;

	len = ft_strlen(str);
	if (ft_strnstr(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == NULL)
	{
		// ft_putstr("NNN\n");
		return (0);
	}
	if (len - 8 > PROG_NAME_LENGTH)
	{
		// ft_putstr("VVV\n");

		return (0);
	}
	i = ft_strlen(NAME_CMD_STRING);
	while (str[i] && (str[i] == ' ' || str[i] == '\n'))
		i++;
	if (!str[i])
		return (0);
	if (len - i - (int)ft_strlen(NAME_CMD_STRING - 2) > PROG_NAME_LENGTH)
		return (0);
	if (i == (int)ft_strlen(NAME_CMD_STRING) || str[i] != '"' || str[len - 1] != '"')
		return (0);
	i++;
	j = 0;
	while (i < len - 1)
	{
		if (ft_strchr(CMD_CHARS, str[i]) == NULL)
			return (0);
		header->prog_name[j] = str[i];
		i++;
		j++;
	}
	header->prog_name[j] = '\0';
	return (1);
}

int	check_file_comment(char *str, t_header *header)
{
	int i;
	int	len;
	int	j;

	len = ft_strlen(str);
	if (ft_strnstr(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == NULL)
	{
		// ft_putstr("NNN\n");
		return (0);
	}
	if (len - 8 > COMMENT_LENGTH)
	{
		// ft_putstr("VVV\n");

		return (0);
	}
	i = ft_strlen(COMMENT_CMD_STRING);
	while (str[i] && (str[i] == ' ' || str[i] == '\n'))
		i++;
	if (!str[i])
		return (0);
	if (len - i - (int)ft_strlen(COMMENT_CMD_STRING - 2) > COMMENT_LENGTH)
		return (0);
	if (i == (int)ft_strlen(COMMENT_CMD_STRING) || str[i] != '"' || str[len - 1] != '"')
		return (0);
	i++;
	j = 0;
	while (i < len - 1)
	{
		if (ft_strchr(CMD_CHARS, str[i]) == NULL)
			return (0);
		header->comment[j] = str[i];
		i++;
		j++;
	}
	header->comment[j] = '\0';
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
