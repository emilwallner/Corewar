/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:19:51 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/21 11:27:02 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// int	set_name(t_instruction *line, char *str, int i)
// {
// 	int	name_end;
//
// 	name_end = 0;
// 	if (ft_strchr(str + i, ' ') == NULL && ft_strchr(str + i, '\t') == NULL)
// 		return (-1);
// 	if (ft_strchr(str + i, ' ') == NULL || ft_strchr(str + i, '\t') == NULL)
// 		name_end = ft_strchr(str + i, ' ') == NULL ? ft_strchr(str + i, '\t') -
// 		(str + i) : ft_strchr(str + i, ' ') - (str + i);
// 	else
// 		name_end = MIN(ft_strchr(str + i, ' ') - (str + i),
// 		ft_strchr(str + i, '\t') - (str + i));
// 	line->name = ft_strsub(str, i, name_end);
// 	return (name_end + 1);
// }
//
// int	set_params(t_instruction *line, char *str, int i)
// {
// 	int	param_end;
//
// 	if (ft_strchr(str + i, ' ') == NULL && ft_strchr(str + i, '\t') == NULL)
// 		param_end = ft_strlen(str);
// 	else if (!ft_strchr(str + i, ' ') || !ft_strchr(str + i, '\t'))
// 		param_end = ft_strchr(str + i, ' ') == NULL ? ft_strchr(str + i, '\t') -
// 		(str + i) : ft_strchr(str + i, ' ') - (str + i);
// 	else
// 		param_end = MIN(ft_strchr(str + i, ' ') - (str + i),
// 		ft_strchr(str + i, '\t') - (str + i));
// 	line->params = ft_strsub(str, i, param_end);
// 	// ft_putstr(line->params);
// 	// ft_putstr(str);
// 	// ft_putchar('\n');
// 	// ft_putstr("fff\n");
// 	// ft_putnbr(param_end);
// 	if (i + param_end < (int)ft_strlen(str))
// 		while (str[++param_end + i])
// 		{
// 			if (str[i + param_end] != COMMENT_CHAR && str[i + param_end] != ' ' &&
// 			str[i + param_end] != '\t')
// 			{
// 				// ft_putnbr(param_end);
// 				// ft_putchar(str[param_end]);
// 				// ft_putchar('\n');
// 				// ft_putstr(str);
// 				// ft_putstr("GGGGGGG\n");
// 				return (-1);
// 			}
// 			if (str[i + param_end] == COMMENT_CHAR)
// 			{
// 				while (str[++param_end + i])
// 					if (!ft_strchr(LABEL_CHARS, str[i + param_end]))
// 						return (-1);
// 			}
// 		}
// 	return (1);
// }

int	set_t_instruction(t_instruction *line, char **str)
{
	int	i;
	int	j;
	int	end;

	end = 0;
	i = 0;
	j = 1;
	if (!str[0])
		return (1);
	if (str[0] && ft_strchr(str[0], LABEL_CHAR) && check_valid_label(str[0]) == 1)
	{
		// ft_putstr("IS LABEL\n");
		i++;
		if (str[1] == NULL)
			return (1);
	}
	// ft_putstr("OUT L\n");

	if (str[i] && str[i][0] == COMMENT_CHAR)
	{
		if (str[i + 1] != NULL)
		{
			// ft_putstr("zzz\n");
			return (0);
		}
		while (str[1][j])
		{
			if (ft_strchr(LABEL_CHARS, str[1][j]) == NULL)
			{
				// ft_putstr("xxx\n");
				return (0);
			}
			j++;
		}
		return (1);
	}
	if (!str[i])
	{
		// ft_putstr("ccc\n");
		return (0);
	}
	if (!(line->name = ft_strdup(str[i])))
	{
		// ft_putstr("vvv\n");
		return (0);
	}
	i++;
	if (!str[i])
	{
		// ft_putstr("bbb\n");
		return (0);
	}
	if (!(line->params = ft_strdup(str[i])))
	{
		// ft_putstr("nnn\n");
		return (0);
	}
	i++;
	if (!str[i])
		return (1);
	if (str[i][0] != COMMENT_CHAR || str[i + 1])
	{
		// ft_putstr("mmm\n");
		return (0);
	}
	while (str[i][j])
	{
		if (ft_strchr(LABEL_CHARS, str[i][j]) == NULL)
		{
			// ft_putstr(str[i]);
			// ft_putstr("lll\n");
			return (0);
		}
		j++;
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
	while (tasm->asm_master[i] != NULL)
	{
		// ft_putstr("YYY\n");
		ft_bzero(&line, sizeof(t_instruction));
		if (!tasm->asm_master[i][0])
			i++;
		else if (tasm->asm_master[i][0][0] == COMMENT_CHAR)
		{
			j = 1;
			while (tasm->asm_master[i][0][j])
			{
				if (ft_strchr(LABEL_CHARS, tasm->asm_master[i][0][j]) == NULL || tasm->asm_master[i][1])
				{
					// ft_putstr("TTT\n");
					return (0);
				}
				j++;
			}
			i++;
		}
		else if (tasm->asm_master[i][0])
		{
			// printf("\ntasm->asm_tab[i] %s i = %d\n", tasm->asm_tab[i], i);
			if (set_t_instruction(&line, tasm->asm_master[i]) == 0)
			{
				// ft_putstr("CCC\n");
				return (0);
			}
			// ft_putstr("SSSS\n");
			//printf(">>>> LINE -name %s -params %s\n", line.name, line.params);
			if (line.name && (id = get_id_by_name(tasm, line.name)) < 1)
			{
				// ft_putstr("AAA\n");
				return (0);
			}
			// printf("id funtion %i\n", id);
			// ft_putstr("aaaa\n");
			// printf("name %s\n", g_op_tab[id].name);

			if (line.params && check_params(line.params, tasm->op_tab[id], tasm) == 0)
			{
				// ft_putstr("BBB\n");
				return (0);
			}
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
