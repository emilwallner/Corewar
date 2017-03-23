/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_asm_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:16:40 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/23 15:58:56 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	str_cross(char *str, int *i, int j)
{
	while (str[*i] && str[*i] != COMMENT_CHAR && (str[*i] == ' ' ||
	str[*i] == '\t'))
		(*i)++;
	while (str[*i + j] && str[*i + j] != COMMENT_CHAR && str[*i + j] != ' ' &&
	str[*i + j] != '\t')
		j++;
	return (j);
}

int			set_master_line(char **asm_master_line, char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!str || str[0] == '\0')
			asm_master_line[count] = NULL;
		j = str_cross(str, &i, 0);
		while (str[i] == COMMENT_CHAR && str[i + j])
			j++;
		if (j)
		{
			if (!(asm_master_line[count] = ft_strsub(str + i, 0, j)))
				return (0);
			count++;
		}
		i += j;
	}
	asm_master_line[count] = NULL;
	return (1);
}

int			count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str[i] == COMMENT_CHAR)
		{
			count++;
			break ;
		}
		else if (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t')
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

int			split_line(char ***asm_master, t_asm *tasm)
{
	int	i;
	int	nb_word;

	if (!(asm_master[0] = ft_memalloc(sizeof(char*) * (1 + 1))))
		return (0);
	if (!(asm_master[1] = ft_memalloc(sizeof(char*) * (1 + 1))))
		return (0);
	if (!(asm_master[0][0] = ft_strdup(tasm->asm_tab[0])))
		return (0);
	if (!(asm_master[1][0] = ft_strdup(tasm->asm_tab[1])))
		return (0);
	asm_master[0][1] = NULL;
	asm_master[1][1] = NULL;
	i = 2;
	while (tasm->asm_tab[i])
	{
		nb_word = count_word(tasm->asm_tab[i]);
		if (!(asm_master[i] = ft_memalloc(sizeof(char*) * (nb_word + 1))))
			return (0);
		if (set_master_line(asm_master[i], tasm->asm_tab[i]) == 0)
			return (0);
		i++;
	}
	asm_master[i] = NULL;
	return (1);
}
