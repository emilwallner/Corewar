/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/21 17:40:34 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int ac, char **av)
{
	t_env e;

	// printf("PROG_NAME_LENGTH is %i\n", PROG_NAME_LENGTH);
	init_e(&e, ac, av);
	// printf("\n*** FT_PRINT_STRING ***\n");
	// ft_print_strings(&e, ac);
	// printf("\n\n*** FT_PARSING ***\n\n");
	ft_parsing(&e, ac);
	// printf("\n\n*** FT_BUILD_VM ***\n\n");
	ft_build_vm(&e, ac);

	// ft_init_cursor(&e);
	// ft_move_cursors(&e);
	ft_debug(e);
	//ft_check_args(e, 4, 84);
	return(0);
}
