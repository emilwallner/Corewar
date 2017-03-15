/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:21:54 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/15 19:16:43 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_file_name(char *str, t_header *header)
{
	int i;
	int	len;

	len = ft_strlen(str);
	if (ft_strnstr(str, NAME_CMD_STRING, 5) == NULL)
		return (0);
	if (str[5] != ' ' || str[6] != '"' || str[len] != '"')
		return (0);
	if (len - 8 > PROG_NAME_LENGTH)
		return (0);
	i = 7;
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
	if (ft_strnstr(str, COMMENT_CMD_STRING, 5) == NULL)
		return (0);
	if (str[8] != ' ' || str[9] != '"' || str[len] != '"')
		return (0);
	if (len - 11 > PROG_NAME_LENGTH)
		return (0);
	i = 10;
	while (i < len - 1)
	{
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL)
			return (0);
		header->prog_name[i - 10] = str[i];
		i++;
	}
	return (1);
}

// int	check_file_instructions(char **asm_tab)
// {
// 	int i;
//
// 	i = 2;
// 	while (asm_tab[i] != NULL)
// 	{
// 		if ()
// 	}
// }

int	check_file(char **asm_tab, t_header *header)
{
	ft_bzero(header, sizeof(t_header));
	if (!asm_tab[0] || check_file_name(asm_tab[0], header) == 0)
	{
		return (0);
	}
	if (!asm_tab[1] || check_file_comment(asm_tab[0], header) == 0)
	{
		return (0);
	}
	// if (!asm_tab[2] || check_file_instructions(asm_tab) == 0)
	// {
	// 	return (0);
	// }
	return (1);
}
