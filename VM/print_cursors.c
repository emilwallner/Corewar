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

void	ft_print_cursor(t_env *e)
{
	t_cursor *temp;
	int 	hex;

	temp = e->head;
	while(temp)
	{
		ft_printf("Cursor for Player %d, ID: %d, Map location: %d", temp->player, temp->id, temp->index);
		hex = 0xFF & (e->arena[temp->index]);
		(hex <= 0xF) ? ft_printf("0%x", hex) : ft_printf("%x", hex);
		temp = temp->next;
	}
}
