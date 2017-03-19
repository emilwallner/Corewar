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


void	ft_live(t_env *e)
{
	ft_printf("live\n");
	(void)e;
}
void	ft_ld(t_env *e)
{
	ft_printf("ld\n");
	(void)e;
}

void	ft_st(t_env *e)
{
	ft_printf("st\n");
	(void)e;
}

void	ft_add(t_env *e)
{
	ft_printf("add\n");
	(void)e;
}

void	ft_sub(t_env *e)
{
	ft_printf("sub\n");
	(void)e;
}

void	ft_and(t_env *e)
{
	ft_printf("and\n");
	(void)e;
}

void	ft_or(t_env *e)
{
	ft_printf("or\n");
	(void)e;
}

void	ft_xor(t_env *e)
{
	ft_printf("xor\n");
	(void)e;
}

void	ft_zjmp(t_env *e)
{
	ft_printf("zjmp\n");
	(void)e;
}

void	ft_ldi(t_env *e)
{
	ft_printf("live\n");
	(void)e;
}

void	ft_sti(t_env *e)
{
	ft_printf("live\n");
	(void)e;
}

void	ft_fork(t_env *e)
{
	ft_printf("live\n");
	(void)e;
}

void	ft_lld(t_env *e)
{
	ft_printf("lld\n");
	(void)e;
}

void	ft_lldi(t_env *e)
{
	ft_printf("lldi\n");
	(void)e;
}

void	ft_lfork(t_env *e)
{
	ft_printf("lfork\n");
	(void)e;
}

void	ft_aff(t_env *e)
{
	ft_printf("aff\n");
	(void)e;
}
