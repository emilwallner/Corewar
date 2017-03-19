/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:21:54 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/19 16:35:38 by mhaziza          ###   ########.fr       */
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
	if (len - 11 > COMMENT_LENGTH)
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

int	check_instructions(t_asm *tasm)
{
	int				i;
	int				id;
	t_instruction	line;
	int				j;

	i = 2;
	while (tasm->asm_tab[i] != NULL)
	{
		// ft_putstr("YYY\n");
		if (!tasm->asm_tab[i][0])
			i++;
		else if (tasm->asm_tab[i][0] == COMMENT_CHAR)
		{
			j = 1;
			while (tasm->asm_tab[i][j])
			{
				if (ft_strchr(LABEL_CHARS, tasm->asm_tab[i][j]) == NULL)
					return (0);
				j++;
			}
			i++;
		}
		else if (tasm->asm_tab[i][0])
		{
			// printf("\ntasm->asm_tab[i] %s i = %d\n", tasm->asm_tab[i], i);
			if (set_t_instruction(&line, tasm->asm_tab[i]) == 0)
			{
				// ft_putstr("ZZZZZZZ\n");
				return (0);
			}
			// printf(">>>> LINE -label %s -name %s -params %s\n", line.label, line.name, line.params);
			if ((id = get_id_by_name(tasm, line.name)) < 1)
				return (0);
			// printf("id funtion %i\n", id);
			// ft_putstr("aaaa\n");
			// printf("name %s\n", g_op_tab[id].name);

			if (check_params(line.params, tasm->op_tab[id], tasm) == 0)
				return (0);
			i++;
			// printf("check params OK\n");
		}
		else
			i++;
	}
	// i = 0;
	// while (i < tasm->nb_labels)
	// {
	// 	ft_putstr("XXXXXXXX\n");
	// 	ft_putstr(tasm->labels[i].label);
	// 	ft_putchar('\n');
	// 	ft_putnbr(tasm->labels[i].index);
	// 	ft_putchar('\n');
	// 	i++;
	// }
	return (1);
}

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
