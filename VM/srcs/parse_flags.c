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

int		find_next_value(t_env *e)
{
	int i;

	i = smallest_number(e);
	i++;
	while (ft_loop_dup(e, i))
	{
		if (i == INT_MAXA)
			ft_exit(e, 7);
		else
			i++;
	}
	return (i);
}

void	ft_capture_number(t_env *e, char *nbr, int *i, int args)
{
	long temp;

	if ((*i + 3) > args)
		ft_exit(e, 11);
	*i += 1;
	e->dump = 1;
	ft_check_number(e, nbr);
	if (ft_strlen(nbr) > 15)
		ft_exit(e, 12);
	temp = ft_atoli(nbr);
	if (temp > INT_MAXA || temp < 0)
		ft_exit(e, 19);
	else
		e->dump_value = temp;
	*i += 1;
}

void	ft_add_player_w_nbr(t_env *e, char *nbr, int args, int *i)
{
	long	temp;
	int		players;

	players = e->player_amount;
	if ((*i + 3) > args)
		ft_exit(e, 13);
	ft_check_number(e, nbr);
	if (ft_strlen(nbr) > 15)
		ft_exit(e, 7);
	temp = ft_atoli(nbr);
	if (temp > INT_MAXA || temp < INT_MINA)
		ft_exit(e, 15);
	if (ft_loop_dup(e, temp))
		ft_exit(e, 9);
	e->player[players].nbr = temp;
	*i += 2;
	e->player[players].file_pos = *i;
}

void	ft_add_player_empty(t_env *e, int *i, int players)
{
	int	value;

	if (players == 0)
		value = 1;
	else
		value = find_next_value(e);
	e->player[players].nbr = value;
	e->player[players].file_pos = *i;
}

void	ft_parse_flags(t_env *e, int args, char **av)
{
	int	i;

	i = 1;
	e->player_amount = 0;
	if (ft_strequ(av[i], "-dump"))
		ft_capture_number(e, av[i + 1], &i, args);
	else if (ft_strequ(av[i], "-visual"))
		ft_add_bonus(e, args, &i);
	while (i < args)
	{
		if (ft_strequ(av[i], "-n"))
			ft_add_player_w_nbr(e, av[i + 1], args, &i);
		else
			ft_add_player_empty(e, &i, e->player_amount);
		e->player_amount += 1;
		if (e->player_amount > MAX_PLAYERS)
			ft_exit(e, 8);
		i++;
	}
	e->cursors = e->player_amount;
}
