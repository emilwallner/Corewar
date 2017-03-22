/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:19:51 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/22 16:45:57 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	if_comment_or_label(int *i, int *j, char **str)
{
	if (!str[0])
		return (1);
	if (str[0] && ft_strchr(str[0], LABEL_CHAR) &&
		check_valid_label(str[0]) == 1)
	{
		(*i)++;
		if (str[1] == NULL)
			return (1);
	}
	if (str[*i] && str[*i][0] == COMMENT_CHAR)
	{
		if (str[*i + 1] != NULL)
			return (0);
		while (str[1][*j])
		{
			if (ft_strchr(LABEL_CHARS, str[1][*j]) == NULL)
				return (0);
			(*j)++;
		}
		return (1);
	}
	if (!str[*i])
		return (0);
	return (2);
}

int			set_t_instruction(t_instruction *line, char **str)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	if (!(ret = if_comment_or_label(&i, &j, str)) || ret == 1)
		return (ret);
	if (!(line->name = ft_strdup(str[i])))
		return (0);
	i++;
	if (!str[i])
		return (0);
	if (!(line->params = ft_strdup(str[i])))
		return (0);
	i++;
	if (!str[i])
		return (1);
	if (str[i][0] != COMMENT_CHAR || str[i + 1])
		return (0);
	while (str[i][++j])
		if (ft_strchr(COMMENT_CHARS, str[i][j]) == NULL)
			return (0);
	return (1);
}

static int	check_instruction_attribute(int i, t_asm *tasm)
{
	t_instruction	line;
	int				id;

	ft_bzero(&line, sizeof(t_instruction));
	if (set_t_instruction(&line, tasm->asm_master[i]) == 0)
		return (0);
	if (line.name && (id = get_id_by_name(tasm, line.name)) < 1)
		return (0);
	if (line.params && !check_params(line.params, tasm->op_tab[id], tasm))
	{
		if (line.name)
			free(line.name);
		if (line.params)
			free(line.params);
		return (0);
	}
	if (line.name)
		free(line.name);
	if (line.params)
		free(line.params);
	return (1);
}

int			check_instructions(t_asm *tasm)
{
	int				i;
	int				j;

	i = 2;
	while (tasm->asm_master[i] != NULL)
	{
		if (!tasm->asm_master[i][0])
			;
		else if (tasm->asm_master[i][0][0] == COMMENT_CHAR)
		{
			j = 1;
			while (tasm->asm_master[i][0][j])
			{
				if (ft_strchr(COMMENT_CHARS, tasm->asm_master[i][0][j]) == NULL)
					return (0);
				j++;
			}
		}
		else if (tasm->asm_master[i][0])
			if (!check_instruction_attribute(i, tasm))
				return (0);
		i++;
	}
	return (1);
}
