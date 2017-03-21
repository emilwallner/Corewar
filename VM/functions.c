/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/20 17:07:59 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void	ft_live(t_env *e, t_cursor *cursor)
{
	(void)cursor;
	e->lives += 1;
	e->player[1].live += 1;
	e->winner = 1;
}

// void	ft_live_execute(t_env *e, t_cursor *cursor)
// {
// 	// execute the live command
// }

void	ft_ld(t_env *e, t_cursor *cursor)
{
	ft_printf("ld\n");
	(void)e;
	(void)cursor;
}

void	ft_st(t_env *e, t_cursor *cursor)
{
	ft_printf("st\n");
	(void)e;
	(void)cursor;
}

void	ft_add(t_env *e, t_cursor *cursor)
{
	ft_printf("add\n");
	(void)e;
	(void)cursor;
}

void	ft_sub(t_env *e, t_cursor *cursor)
{
	ft_printf("sub\n");
	(void)e;
	(void)cursor;
}

void	ft_and(t_env *e, t_cursor *cursor)
{
	ft_printf("and\n");
	(void)e;
	(void)cursor;
}

void	ft_or(t_env *e, t_cursor *cursor)
{
	ft_printf("or\n");
	(void)e;
	(void)cursor;
}

void	ft_xor(t_env *e, t_cursor *cursor)
{
	ft_printf("xor\n");
	(void)e;
	(void)cursor;
}

void	ft_zjmp(t_env *e, t_cursor *cursor)
{
	ft_printf("zjmp\n");
	(void)e;
	(void)cursor;
}

void	ft_ldi(t_env *e, t_cursor *cursor)
{
	ft_printf("live\n");
	(void)e;
	(void)cursor;
}

void	ft_sti(t_env *e, t_cursor *cursor)
{
	ft_printf("live\n");
	(void)e;
	(void)cursor;
}

void	ft_fork(t_env *e, t_cursor *cursor)
{
	ft_printf("live\n");
	(void)e;
	(void)cursor;
}

void	ft_lld(t_env *e, t_cursor *cursor)
{
	ft_printf("lld\n");
	(void)e;
	(void)cursor;
}

void	ft_lldi(t_env *e, t_cursor *cursor)
{
	ft_printf("lldi\n");
	(void)e;
	(void)cursor;
}

void	ft_lfork(t_env *e, t_cursor *cursor)
{
	ft_printf("lfork\n");
	(void)e;
	(void)cursor;
}

void	ft_aff(t_env *e, t_cursor *cursor)
{
	ft_printf("aff\n");
	(void)e;
	(void)cursor;
}
