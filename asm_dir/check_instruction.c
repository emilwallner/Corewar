/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:19:51 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/19 18:45:14 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int	set_t_instruction(t_instruction *line, char *str)
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
