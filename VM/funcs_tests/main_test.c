/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:23:13 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 15:35:26 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
** This part is to test each function while the core algo is being built
*/

void	ft_debug(t_env e)
{
	t_cursor *cursor;

	cursor = (t_cursor*)malloc(sizeof(*cursor) * 10);
	printf(RED "\n###### FUNCTION TEST : ft_ld.c ######\n\n" RESET);

	ft_debug_ld(e, &cursor[0]);
	ft_debug_ld2(e, &cursor[1]);
}
