/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:23:13 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 11:14:40 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/vm.h"

/*
** This part is to test each function while the core algo is being built
*/
void	ft_tests_st(t_env e, t_cursor *cursor);
void	ft_tests_st2(t_env e, t_cursor *cursor);

void	ft_debug(t_env e)
{
	t_cursor *cursor;

	cursor = (t_cursor*)malloc(sizeof(*cursor) * 10);

	printf(RED "\n###### FUNCTION TEST : ft_st.c ######\n\n" RESET);
	ft_tests_st(e, &cursor[0]);
	// ft_tests_st2(e, &cursor[1]);

	printf(RED "\n###### FUNCTION TEST : ft_ld.c ######\n\n" RESET);

	ft_tests_ld(e, &cursor[0]);
	ft_tests_ld2(e, &cursor[1]);

	printf(RED "\n###### FUNCTION TEST : ft_lld.c ######\n\n" RESET);

	ft_tests_lld(e, &cursor[0]);
	ft_tests_lld2(e, &cursor[1]);

	printf(RED "\n###### FUNCTION TEST : ft_ldi.c ######\n\n" RESET);

	// ft_tests_ldi(e, &cursor[0]);
	// ft_tests_ldi2(e, &cursor[1]);

	printf(RED "\n###### FUNCTION TEST : ft_add.c ######\n\n" RESET);

	ft_tests_add(e, &cursor[0]);
	ft_tests_add2(e, &cursor[1]);

	printf(RED "\n###### FUNCTION TEST : ft_sub.c ######\n\n" RESET);

	ft_tests_sub(e, &cursor[0]);
	ft_tests_sub2(e, &cursor[1]);

	printf(RED "\n###### FUNCTION TEST : ft_and.c ######\n\n" RESET);

 	// ft_tests_and(e, &cursor[0]);
 	// ft_tests_and1(e, &cursor[1]);
 	// ft_tests_and2(e, &cursor[2]);
 	// ft_tests_and3(e, &cursor[2]);
	// ft_tests_and4(e, &cursor[2]);
	// ft_tests_and5(e, &cursor[2]);
	// ft_tests_and6(e, &cursor[2]);
	// ft_tests_and7(e, &cursor[2]);
	// ft_tests_and8(e, &cursor[2]);
	// ft_tests_and4(e, &cursor[2]);
	// ft_tests_and5(e, &cursor[2]);
	// ft_tests_and6(e, &cursor[2]);
	// ft_tests_and7(e, &cursor[2]);
	// ft_tests_and8(e, &cursor[2]);

	printf(RED "\n###### FUNCTION TEST : ft_or.c ######\n\n" RESET);

	// ft_tests_or(e, &cursor[0]);
	// ft_tests_or1(e, &cursor[1]);
	// ft_tests_or2(e, &cursor[2]);
	// ft_tests_or3(e, &cursor[2]);
	// ft_tests_or4(e, &cursor[2]);
	// ft_tests_or5(e, &cursor[2]);
	// ft_tests_or6(e, &cursor[2]);
	// ft_tests_or7(e, &cursor[2]);
	// ft_tests_or8(e, &cursor[2]);
}
