/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:58:11 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/16 17:52:42 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int check_register(char *params, t_op top, int p)
{
	int	i;

	if ((T_REG & top.params_type[p]) != T_REG)
		return (0);
	i = 0;
	while (params[++i] && params[i] != SEPARATOR_CHAR)
		if (!ft_isdigit(params[i]) || i > 3)
			return (0);
	if (ft_atoi(params + 1) <= 0 || ft_atoi(params + 1) > REG_NUMBER)
		return (0);
	return (1);
}

static int check_direct(char *params, t_op top, int p, t_asm *tasm)
{
	int	i;
	int	j;
	int	is_found;
	char *label;

	if ((T_DIR & top.params_type[p]) != T_DIR)
		return (0);
	i = 0;
	if (params[1] == LABEL_CHAR)
	{
		j = 0;
		is_found = 0;
		label = ft_strchr(params, SEPARATOR_CHAR) ? ft_strsub(params, 2, ft_strchr(params, SEPARATOR_CHAR) - (params + 2)) : ft_strsub(params, 2, ft_strlen(params));
		while (j < tasm->nb_labels && !is_found)
			if (!ft_strcmp(tasm->labels[j].label, label))
				is_found = 1;
		if (!is_found)
			return (0);
	}
	else
	{
		i = 0;
		while (params[++i] && params[i] != SEPARATOR_CHAR)
			if (!ft_isdigit(params[i]) || i > 11)
				return (0);
		if (top.label_size && ft_atoli(params + 1) > INT_MAX)
			return (0);
		else if (ft_atoli(params + 1) > 65535)
			return (0);
	}
	return (1);
}

static int check_indirect(char *params, t_op top, int p, t_asm *tasm)
{
	int	i;
	int	j;
	int	is_found;
	char *label;

	if ((T_IND & top.params_type[p]) != T_IND)
	return (0);
	i = 0;
	if (params[0] == LABEL_CHAR)
	{
		j = 0;
		is_found = 0;
		label = ft_strchr(params, SEPARATOR_CHAR) ? ft_strsub(params, 1, ft_strchr(params, SEPARATOR_CHAR) - (params + 1)) : ft_strsub(params, 1, ft_strlen(params));
		while (j < tasm->nb_labels && !is_found)
			if (!ft_strcmp(tasm->labels[j].label, label))
				is_found = 1;
		if (!is_found)
			return (0);
	}
	else
	{
		i = 0;
		while (params[++i] && params[i] != SEPARATOR_CHAR)
			if (!ft_isdigit(params[i]) || i > 11)
				return (0);
		if (top.label_size && ft_atoli(params + 1) > INT_MAX)
			return (0);
		else if (ft_atoli(params + 1) > 65535)
			return (0);
	}
	return (1);
}

int		check_params(char *params, t_op top, t_asm *tasm)
{
	int	i;
	int	comas;
	int	p;

	i = -1;
	comas = 1;
	while (params[++i])
		if (params[i] == SEPARATOR_CHAR)
			comas++;
	printf("\nnb commas %i top.nb_params %i top.name %s\n", comas, top.nb_params, top.name);
	if (comas != top.nb_params)
		return (0);
	i = 0;
	p = 0;
	while (params[i] && p < top.nb_params)
	{
		if (params[i] == 'r')
		{ft_putstr(">> R\n");
			if (!check_register(params + i, top, p))
				return (0);
		}
		else if (params[i] == DIRECT_CHAR)
		{ft_putstr(">> DIR\n");
			if (!check_direct(params + i, top, p, tasm))
				return (0);
		}
		else
		{ft_putstr(">> IND\n");
			if (!check_indirect(params + i, top, p, tasm))
				return (0);
		}
		if (ft_strchr(params + i, SEPARATOR_CHAR))
			i += ft_strchr(params + i, SEPARATOR_CHAR) - (params + i) + 1;
		else
			i = ft_strlen(params);
		printf("%s int i %i\n", params, i);
		p++;
	}
	return (1);
}
