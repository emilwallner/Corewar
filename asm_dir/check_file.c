/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:21:54 by tlenglin          #+#    #+#             */
/*   Updated: 2017/04/26 16:04:44 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_file_name(char *s, t_header *header)
{
	int	i;
	int	l;
	int	j;

	l = ft_strlen(s);
	if (ft_strnstr(s, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == NULL)
		return (0);
	i = ft_strlen(NAME_CMD_STRING);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		return (0);
	if (l - i - (int)ft_strlen(NAME_CMD_STRING - 2 - 1) > PROG_NAME_LENGTH)
		return (0);
	if (i == (int)ft_strlen(NAME_CMD_STRING) || s[i] != '"' || s[l - 1] != '"')
		return (0);
	j = -1;
	while (++i < l - 1)
	{
		if (ft_strchr(CMD_CHARS, s[i]) == NULL)
			return (0);
		header->prog_name[++j] = s[i];
	}
	header->prog_name[++j] = '\0';
	return (1);
}

int	check_file_comment(char *s, t_header *header)
{
	int i;
	int	l;
	int	j;

	l = ft_strlen(s);
	if (!ft_strnstr(s, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (0);
	i = ft_strlen(COMMENT_CMD_STRING);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i] || l - i - (int)ft_strlen(COMMENT_CMD_STRING - 2 - 1) >
	COMMENT_LENGTH)
		return (0);
	if (i == (int)ft_strlen(COMMENT_CMD_STRING) || s[i] != '"' ||
	s[l - 1] != '"')
		return (0);
	j = -1;
	while (++i < l - 1)
	{
		if (ft_strchr(CMD_CHARS, s[i]) == NULL)
			return (0);
		header->comment[++j] = s[i];
	}
	header->comment[++j] = '\0';
	return (1);
}

int	check_file(t_asm *tasm, t_header *header)
{
	ft_bzero(header, sizeof(t_header));
	if (!tasm->asm_master[0][0] ||
		check_file_name(tasm->asm_master[0][0], header) == 0)
		return (eol(4));
	if (!tasm->asm_master[1][0] ||
		check_file_comment(tasm->asm_master[1][0], header) == 0)
		return (eol(5));
	if (!tasm->asm_master[2] || check_instructions(tasm) == 0)
		return (0);
	return (1);
}
