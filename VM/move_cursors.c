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


void 	ft_move_cursors(t_env *e)
{
	int i;
	t_cursor *temp;

	temp = e->head;
	i = 0;
	while (i < MEM_SIZE)
	{
		//ft_print_cursor(e);
		temp->index += 1;
		if(temp->index == MEM_SIZE + 1)
			temp->index = 0;
		ft_print_function(temp->index, temp, e);
		temp = temp->next;
		i++;
	}
}
