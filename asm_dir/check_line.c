/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:36:16 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/16 19:02:08 by mhaziza          ###   ########.fr       */
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

int	check_label(char *str)
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

int	get_id_by_name(char *name)
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

int	check_instructions(t_asm *tasm)
{
	int				i;
	int				id;
	t_instruction	line;

	i = 2;
	while (tasm->asm_tab[i] != NULL)
	{
		if (!tasm->asm_tab[i][0] || tasm->asm_tab[i][0] == COMMENT_CHAR)
			i++;
		else if (tasm->asm_tab[i][0])
		{
			// printf("tasm->asm_tab[i] %s\n", tasm->asm_tab[i]);
			if (set_variables(&line, tasm, tasm->asm_tab[i], i) == 0)
			{
				// ft_putstr("ZZZZZZZ\n");
				return (0);
			}
			// printf("\n>>>> LINE label %s name %s params %s\n", line.label, line.name, line.params);
			if ((id = get_id_by_name(line.name) - 1) == -1)
				return (0);
			// printf("id funtion %i\n", id);
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
