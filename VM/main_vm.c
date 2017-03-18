/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/18 17:48:22 by nsabbah          ###   ########.fr       */
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
	printf("\n*** FT_PARSING ***\n");
	ft_parsing(&e, ac);
	ft_build_vm(&e, ac);
}
