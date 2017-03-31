/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:04:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/31 19:25:25 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_player_to_arena(t_env *e, int i, int *k)
{
	int	count;

	count = 0;
	while (count < e->player[i].inst_len)
	{
		e->a[*k].hex = 0xFF & e->player[i].inst[count];
		e->a[*k].color = 1 + (i % 6);
		e->a[*k].prevcolor = 1 + (i % 6);
		*k += 1;
		count++;
	}
}

void	ft_build_arena(t_env *e)
{
	int			i;
	static int	k;

	i = 0;
	k = 0;
	while (i < e->player_amount)
	{
		e->player[i].index_start = (MEM_SIZE / e->player_amount) * i;
		e->player[i].live = 0;
		k = (MEM_SIZE / e->player_amount) * i;
		ft_player_to_arena(e, i, &k);
		i++;
	}
}
