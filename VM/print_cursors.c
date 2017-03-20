/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/17 17:00:54 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void	ft_print_function(int index, t_cursor *cursor, t_env *e)
{
	int		hex;

	void (*func_ptr[17])(t_env *e, t_cursor *cursor) = {ft_live, ft_live, ft_ld, ft_st, ft_add, ft_sub, ft_and, ft_or, ft_xor, ft_zjmp, ft_ldi, ft_sti, ft_fork, ft_lld, ft_lldi, ft_lfork, ft_aff};
	hex = 0xFF & (e->arena[index]);
	if(hex < 17 && hex > 0)
		(*func_ptr[hex]) (e, cursor);
}




void	ft_print_cursor(t_env *e)
{
	int			i;
	t_cursor	*temp;
	int			hex;

	i = 1;
	temp = e->head;
	while(i < e->player_amount)
	{
		ft_printf("Cursor for Player %d, ID: %d, Map location: %d\n", temp->player, temp->id, temp->index);
		hex = 0xFF & (e->arena[temp->index]);
		(hex <= 0xF) ? ft_printf("0%x\n", hex) : ft_printf("%x\n", hex);
		temp = temp->next;
		i++;
	}
}
