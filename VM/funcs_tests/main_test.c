/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:23:13 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 17:36:45 by nsabbah          ###   ########.fr       */
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

	printf(RED "\n###### FUNCTION TEST : ft_lld.c ######\n\n" RESET);

	ft_debug_lld(e, &cursor[0]);
	ft_debug_lld2(e, &cursor[1]);

	printf(RED "\n###### FUNCTION TEST : ft_ldi.c ######\n\n" RESET);

	ft_debug_ldi(e, &cursor[0]);
	ft_debug_ldi2(e, &cursor[1]);

	printf(RED "\n###### FUNCTION TEST : ft_add.c ######\n\n" RESET);

	ft_debug_add(e, &cursor[0]);
	ft_debug_add2(e, &cursor[1]);
}
