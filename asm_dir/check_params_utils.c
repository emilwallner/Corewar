/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:07:38 by mhaziza           #+#    #+#             */
/*   Updated: 2017/04/26 14:51:07 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_num_params(char *params)
{
	int	i;

	i = 0;
	if (params[0] == '-')
		i++;
	while (params[i] && params[i] != SEPARATOR_CHAR)
	{
		if (!ft_isdigit(params[i]) || i > 11)
			return (0);
		i++;
	}
	return (1);
}

int	check_register(char *params, t_op top, int p)
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

int	check_direct(char *params, t_op top, int p, t_asm *tasm)
{
	int		j;
	int		is_found;
	char	*label;

	if ((T_DIR & top.params_type[p]) != T_DIR)
		return (0);
	if (params[1] == LABEL_CHAR)
	{
		j = -1;
		is_found = 0;
		label = ft_strchr(params, SEPARATOR_CHAR) ?
		ft_strsub(params, 2, ft_strchr(params, SEPARATOR_CHAR) - (params + 2)) :
		ft_strsub(params, 2, ft_strlen(params));
		while (++j < tasm->nb_labels && !is_found)
			if (!ft_strcmp(tasm->labels[j].label, label))
				is_found = 1;
		free(label);
		if (!is_found)
			return (0);
	}
	else if (!check_num_params(params + 1))
		return (0);
	return (1);
}

int	check_indirect(char *params, t_op top, int p, t_asm *tasm)
{
	int		j;
	int		is_found;
	char	*label;

	if ((T_IND & top.params_type[p]) != T_IND)
		return (0);
	if (params[0] == LABEL_CHAR)
	{
		j = -1;
		is_found = 0;
		label = ft_strchr(params, SEPARATOR_CHAR) ?
		ft_strsub(params, 1, ft_strchr(params, SEPARATOR_CHAR) - (params + 1)) :
		ft_strsub(params, 1, ft_strlen(params));
		while (++j < tasm->nb_labels && !is_found)
			if (!ft_strcmp(tasm->labels[j].label, label))
				is_found = 1;
		free(label);
		if (!is_found)
			return (0);
	}
	else if (!check_num_params(params))
		return (0);
	return (1);
}
