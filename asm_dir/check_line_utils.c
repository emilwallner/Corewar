/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:19:51 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/16 19:00:04 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_fill_label(char *label, t_label *labels, int nb, int index)
{
	int	i;

	i = 0;
	while (i < nb && (labels[i]).index > 0)
	{
		if (ft_strcmp((labels[i]).label, label) == 0)
			return (0);
		i++;
	}
	(labels[i]).index = index;
	(labels[i]).label = label;
	return (1);
}

int	set_label(t_instruction *line, t_asm *tasm, char *str, int iline)
{
	int	label_end;

	label_end = ft_strchr(str, LABEL_CHAR) - str + 1;
	line->label = ft_strsub(str, 0, label_end - 1);
	if (!check_fill_label(line->label, tasm->labels, tasm->nb_labels, iline))
		return (-1);
	return (label_end);
}

int	set_name(t_instruction *line, char *str, int i)
{
	int	name_end;

	name_end = 0;
	if (ft_strchr(str + i, ' ') == NULL && ft_strchr(str + i, '\t') == NULL)
		return (-1);
	if (ft_strchr(str + i, ' ') == NULL || ft_strchr(str + i, '\t') == NULL)
		name_end = ft_strchr(str + i, ' ') == NULL ? ft_strchr(str + i, '\t') -
		(str + i) : ft_strchr(str + i, ' ') - (str + i);
	else
		name_end = MIN(ft_strchr(str + i, ' ') - (str + i),
		ft_strchr(str + i, '\t') - (str + i));
	line->name = ft_strsub(str, i, name_end);
	return (name_end + 1);
}

int	set_params(t_instruction *line, char *str, int i)
{
	int	param_end;

	if (ft_strchr(str + i, ' ') == NULL && ft_strchr(str + i, '\t') == NULL)
		param_end = ft_strlen(str);
	else if (!ft_strchr(str + i, ' ') || !ft_strchr(str + i, '\t'))
		param_end = ft_strchr(str + i, ' ') == NULL ? ft_strchr(str + i, '\t') -
		(str + i) : ft_strchr(str + i, ' ') - (str + i);
	else
		param_end = MIN(ft_strchr(str + i, ' ') - (str + i),
		ft_strchr(str + i, '\t') - (str + i));
	line->params = ft_strsub(str, i, param_end);
	if (param_end < (int)ft_strlen(str))
		while (str[++param_end])
		{
			if (str[param_end] != COMMENT_CHAR && str[param_end] != ' ' &&
			str[param_end] != '\t')
				return (-1);
			if (str[param_end] == COMMENT_CHAR)
			{
				while (str[++param_end])
					if (!ft_strchr(LABEL_CHARS, str[param_end]))
						return (-1);
			}
		}
	return (1);
}

int	set_variables(t_instruction *line, t_asm *tasm, char *str, int iline)
{
	int	i;
	int	end;

	end = 0;
	line->label = 0;
	if (check_label(str) == 1)
		if ((end = set_label(line, tasm, str, iline)) == -1)
			return (0);
	i = end;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\n' && str[i] == '#')
		return (1);
	if ((end = set_name(line, str, i)) == -1)
		return (0);
	i += end;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if ((end = set_params(line, str, i)) == -1)
		return (0);
	return (1);
}
