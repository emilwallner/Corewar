/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_atoi_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:28:30 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 11:33:17 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_printspace(int i, char c, t_vars *e)
{
	while (i-- > 0)
		e->totcount += ft_putchar_count(c);
}

void	ft_printprefix(t_vars *e)
{
	if (e->type == UOCTAL || e->type == OCTAL)
		e->totcount += ft_putchar_count('0');
	if (e->type == HEX)
		e->totcount += ft_putstr_count("0x");
	if (e->type == UHEX)
		e->totcount += ft_putstr_count("0X");
	if (e->type == POINTER)
		e->totcount += ft_putstr_count("0x");
}

void	nb_post_flags(t_vars *e)
{
	if (e->width > e->printlen + e->printextra && e->align)
		ft_printspace((e->width - (e->printlen + e->printextra)), ' ', e);
}

void	addsign(char c, t_vars *e)
{
	e->printsign = c;
	e->printextra = 1;
}

void	calc_printextra(t_vars *e)
{
	if ((e->type == UOCTAL || e->type == OCTAL) && e->printprefix)
		e->printextra = 1;
	if ((e->type == HEX || e->type == UHEX) && e->printprefix)
		e->printextra = 2;
	if (e->type == POINTER)
		e->printextra = 2;
}
