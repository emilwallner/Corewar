/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/30 20:24:01 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_loop_dup(t_env *e, int nbr)
{
	int		k;

	k = -1;
	while (++k < e->player_amount)
	{
		if (nbr == e->player[k].nbr)
			return (1);
	}
	return (0);
}

int		smallest_number(t_env *e)
{
	int i;
	int small;

	i = 0;
	small = e->player[i].nbr;
	while (++i < e->player_amount)
	{
		if (small > e->player[i].nbr)
			small = e->player[i].nbr;
	}
	return (small);
}

void	ft_check_number(t_env *e, char *nbr)
{
	int		i;

	i = -1;
	while (nbr[++i])
		if (!(ft_strchr(LABEL_NUMBERS, nbr[i])))
			ft_exit(e, 14);
}

void	ft_add_bonus(t_env *e, int args, int *i)
{
	if ((*i + 2) > args)
		ft_exit(e, 18);
	e->bonus = 1;
	*i += 1;
}
