/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/29 12:33:39 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_aff(t_env *e, t_cursor *cursor)
{
	char	index_extra;
	int		i;

	i = 0;
	index_extra = e->a[MODA(cursor->index + 2)].hex;
	if (index_extra < 0 || index_extra > 15)
	{
		ft_update_cursor(e, cursor, 3);
		return ;
	}
	i = (cursor->reg[index_extra - 1] % 256);
	i = i < 0 ? i + 256 : i;
	// ft_printf("index_extra = %i\n", i);
	// index_extra = get_reg(e, cursor, 1);
	// index_extra = index_extra % 256;
	if(e->bonus)
		printw("%c", i);
	else
		ft_printf("%c", i);
	ft_update_cursor(e, cursor, 3);
}
