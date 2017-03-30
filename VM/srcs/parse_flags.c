/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/28 19:27:32 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_loop_dup(t_env *e, int nbr)
{
	int		k;
	int		c;

	c = 0;
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

int		find_next_value(t_env *e)
{
	int i;

	i = smallest_number(e);
	i++;
	while(ft_loop_dup(e, i))
	{
		if(i == INT_MAXA)
			ft_exit(e, 7);
		else
			i++;
	}
	return (i);
}

void ft_capture_number(t_env *e, char *nbr, int *i)
{
	long temp;

	*i += 1;
	e->dump = 1;
	if(ft_strlen(nbr) > 15)
		ft_exit(e, 7);
	temp = ft_atoli(nbr);
	if(temp > INT_MAXA || temp < INT_MINA)
		ft_exit(e, 7);
	else
		e->dump_value = temp;
	*i += 1;
}

void ft_add_player_w_nbr(t_env *e, char *nbr, int *i, int players)
{
	long temp;

	if(ft_strlen(nbr) > 15)
		ft_exit(e, 7);
	temp = ft_atoli(nbr);
	if(temp > INT_MAXA || temp < INT_MINA)
		ft_exit(e, 7);
	if(ft_loop_dup(e, temp))
		ft_exit(e, 9);
	e->player[players].nbr = temp;
	*i += 2;
	e->player[players].file_pos = *i;
}

void ft_add_player_empty(t_env *e, int *i, int players)
{
	int value;
	if(players == 0)
		value = -4;
	else
		value = find_next_value(e);
	e->player[players].nbr = value;
	e->player[players].file_pos = *i;
}

void		ft_parse_flags(t_env *e, int args, char **av)
{
	int i;

	i = 1;
	e->player_amount = 0;
	if(ft_strequ(av[i], "-dump") && (i + 2) <= args)
		ft_capture_number(e, av[i + 1], &i);
	else if (ft_strequ(av[i], "-visual") && (i + 1) <= args)
	{
		e->bonus = 1;
		i++;
	}
	while(i < args)
	{
		if(ft_strequ(av[i], "-n") && (i + 2) <= args)
			ft_add_player_w_nbr(e, av[i + 1], &i, e->player_amount);
		else
			ft_add_player_empty(e, &i, e->player_amount);
		e->player_amount += 1;
		if(e->player_amount > MAX_PLAYERS)
			ft_exit(e, 8);
		i++;
	}
	e->cursors = e->player_amount;
}
