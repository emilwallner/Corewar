/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:36:16 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/16 17:48:33 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{{0}, 0, {0}, 0, 0, {0}, 0, 0}
};

static int	check_label(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr(LABEL_CHARS, str[0]) == NULL || ft_strchr(str, ':') == NULL)
		return (0);
	while (str[i] != ':')
	{
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

int	count_label(t_asm *tasm)
{
	int	i;

	i = 2;
	while (tasm->asm_tab[i] != NULL)
	{
		if (check_label(tasm->asm_tab[i]) == 1)
			tasm->nb_labels++;
		i++;
	}
	return (1);
}

int get_id_by_name(char *name)
{
    int i;
    i = -1;
    while (++i < 17)
    {
        if (!ft_strcmp(name, g_op_tab[i].name))
            return (g_op_tab[i].id);
    }
    return (0);
}

int	check_and_fill_label(char *label, t_label *labels, int nb, int index)
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

int	set_variables(t_instruction *line, t_asm *tasm, char *str, int iline)
{
	int	i;
	int	label_end;
	int	name_end;
	int	param_end;

	label_end = 0;
	line->label = 0;
	if (check_label(str) == 1)
	{
		label_end = ft_strchr(str, LABEL_CHAR) - str + 1;
		line->label = ft_strsub(str, 0, label_end);
		if (check_and_fill_label(line->label, tasm->labels, tasm->nb_labels, iline) == 0)
			return (0);
	}
	i = label_end;
	// ft_putstr("1\n");
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
		// ft_putstr("2\n");
	if (str[i] == '\n' && str[i] == '#')
		return (1);
	if (ft_strchr(str + i, ' ') == NULL && ft_strchr(str + i, '\t') == NULL)
		return (0);
	// ft_putstr("4\n");
	if (ft_strchr(str + i, ' ') == NULL || ft_strchr(str + i, '\t') == NULL)
		name_end = ft_strchr(str + i, ' ') == NULL ? ft_strchr(str + i, '\t') - (str + i) : ft_strchr(str + i, ' ') - (str + i);
	else
		name_end = MIN(ft_strchr(str + i, ' ') - (str + i), ft_strchr(str + i, '\t') - (str + i));
	// ft_putstr("5\n");
	// ft_putstr(ft_strchr(str + i, ' '));
		// ft_putstr(ft_strchr(str + i, '\t'));
	// ft_putnbr(ft_strchr(str + i, ' ') - (str + i) + 1);
	line->name = ft_strsub(str, i, name_end);
	// ft_putstr(line->name);
	// ft_putstr("\n6\n");
	// printf(">>> %s\n", line->name);
	i += name_end + 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (ft_strchr(str + i, ' ') == NULL && ft_strchr(str + i, '\t') == NULL)
		param_end = ft_strlen(str);
	else if (ft_strchr(str + i, ' ') == NULL || ft_strchr(str + i, '\t') == NULL)
		param_end = ft_strchr(str + i, ' ') == NULL ? ft_strchr(str + i, '\t') - (str + i) : ft_strchr(str + i, ' ') - (str + i);
	else
		param_end = MIN(ft_strchr(str + i, ' ') - (str + i), ft_strchr(str + i, '\t') - (str + i));
	// ft_putnbr(param_end);
	line->params = ft_strsub(str, i, param_end);
	if (param_end < (int)ft_strlen(str))
		while (str[++param_end])
		{
			if (str[param_end] != COMMENT_CHAR && str[param_end] != ' ' && str[param_end] != '\t')
				return (0);
			if (str[param_end] == COMMENT_CHAR)
			{
				while (str[++param_end])
					if (!ft_strchr(LABEL_CHARS, str[param_end]))
						return (0);
			}
		}
	return (1);
}

int	check_instructions(t_asm *tasm)
{
	int		i;
	int		id;
	t_instruction	line;

	i = 2;
	while (tasm->asm_tab[i] != NULL)
	{
		if (tasm->asm_tab[i][0] == COMMENT_CHAR)
			i++;
		else if (tasm->asm_tab[i][0])
		{
			// printf("tasm->asm_tab[i] %s\n", tasm->asm_tab[i]);
			if (set_variables(&line, tasm, tasm->asm_tab[i], i) == 0)
			{
				// ft_putstr("ZZZZZZZ\n");
				return (0);
			}
			printf("line.label %s line.name %s line.params %s\n", line.label, line.name, line.params);
			if ((id = get_id_by_name(line.name) - 1) == 0)
				return (0);
				printf("id funtion %i\n", id);
			if (check_params(line.params, g_op_tab[id], tasm) == 0)
				return (0);
			i++;
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
