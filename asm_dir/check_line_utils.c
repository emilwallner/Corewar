/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:19:51 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/17 16:22:31 by tlenglin         ###   ########.fr       */
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
	labels[i].index = index;
	labels[i].label = label;
	// ft_putstr("TTT\n");
	return (1);
}

int	existing_label(char *label, t_label *labels, int nb)
{
	int	i;

	i = 0;
	while (i < nb && (labels[i]).index > 0)
	{
		if (ft_strcmp((labels[i]).label, label) == 0)
			return (1);
		i++;
	}
	// ft_putstr("XXXX\n");
	return (0);
}

int	check_label(t_instruction *line, t_asm *tasm, char *str)
{
	int	label_end;

	// ft_putstr("RRR\n");
	label_end = ft_strchr(str, LABEL_CHAR) - str + 1;
	line->label = ft_strsub(str, 0, label_end - 1);
	if (!existing_label(line->label, tasm->labels, tasm->nb_labels))
	{
		// ft_putstr("ZZZ\n");
		// printf("label = %s, nb = %d\n", line->label, tasm->nb_labels);
		return (-1);
	}
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
	// ft_putstr(line->params);
	// ft_putstr(str);
	// ft_putchar('\n');
	// ft_putstr("fff\n");
	// ft_putnbr(param_end);
	if (i + param_end < (int)ft_strlen(str))
		while (str[++param_end + i])
		{
			if (str[i + param_end] != COMMENT_CHAR && str[i + param_end] != ' ' &&
			str[i + param_end] != '\t')
			{
				// ft_putnbr(param_end);
				// ft_putchar(str[param_end]);
				// ft_putchar('\n');
				// ft_putstr(str);
				// ft_putstr("GGGGGGG\n");
				return (-1);
			}
			if (str[i + param_end] == COMMENT_CHAR)
			{
				while (str[++param_end + i])
					if (!ft_strchr(LABEL_CHARS, str[i + param_end]))
						return (-1);
			}
		}
	return (1);
}

int	set_variables(t_instruction *line, char *str)
{
	int	i;
	int	end;

	end = 0;
	line->label = 0;
	i = 0;
	if (check_valid_label(str) == 1)
		i = ft_strchr(str, LABEL_CHAR) - str + 1;
	// 	if ((end = check_label(line, tasm, str)) == -1)
	// 		return (0);

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\n' && str[i] == '#')
		return (1);
	if ((end = set_name(line, str, i)) == -1)
		return (0);
	i += end;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if ((set_params(line, str, i)) == -1)
		return (0);
	return (1);
}
