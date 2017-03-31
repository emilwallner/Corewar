/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:35:59 by ewallner          #+#    #+#             */
/*   Updated: 2017/02/10 18:49:53 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include <stdio.h>

void	cutn(t_vars *e, char *str)
{
	if (str[0] == '0' && e->pointlen == 0)
		e->len = 0;
	if (e->plus && !e->neg)
		addsign('+', e);
	if (e->printspace && !e->plus && !e->neg)
		addsign(' ', e);
	if (e->neg)
		addsign('-', e);
}

void	n(intmax_t nb, t_vars *e)
{
	char *str;

	e->len = ft_size_of_intmax(nb, e);
	e->printchar = (e->zero && e->pointlen == -1) ? '0' : ' ';
	str = ft_atoi_intmax(nb, e);
	cutn(e, str);
	e->printlen = (e->len >= e->pointlen) ? e->len : e->pointlen;
	if ((e->printlen + e->printextra >= e->width || e->printchar == '0' || \
				e->align) && e->printextra)
		e->totcount += ft_putchar_count(e->printsign);
	if ((e->width > e->printextra + e->printlen) && !e->align)
		ft_printspace(e->width - (e->printextra + e->printlen), \
				e->printchar, e);
	if (e->printlen + e->printextra < e->width && e->printextra && !e->align \
			&& e->printchar != '0')
		e->totcount += ft_putchar_count(e->printsign);
	if (e->len < e->pointlen)
		ft_printspace(e->pointlen - e->len, '0', e);
	if (!(e->pointlen == 0 && *str == '0'))
		e->totcount += ft_putstr_count(str);
	nb_post_flags(e);
}

void	printpointlen(t_vars *e, char *str)
{
	if (e->len < e->pointlen && (e->type == UHEX || e->type == HEX))
		ft_printspace(e->pointlen - (e->len), '0', e);
	if (e->len < e->pointlen && (e->type == UUNSIGNED || e->type == UNSIGNED))
		ft_printspace(e->pointlen - (e->len), '0', e);
	if (e->len < e->pointlen && (e->type == UOCTAL || e->type == OCTAL))
		ft_printspace(e->pointlen - (e->len + e->printextra), '0', e);
	if (e->pointlen > 0 && (e->type == HEX || e->type == UHEX) && *str == '0')
		e->totcount += ft_putstr_count(str);
}

void	cutu(t_vars *e, char *str)
{
	if (*str == '0' && e->pointlen == 0)
		e->len = 0;
	if (*str == '0' && e->pointlen == 0 && (e->type == OCTAL || \
				e->type == UOCTAL) && e->hash)
		e->len = 1;
	if (*str == '0' && e->type != POINTER)
	{
		e->printprefix = 0;
		e->printextra = 0;
	}
}

void	u(uintmax_t nb, t_vars *e)
{
	char *str;

	e->len = ft_size_of_uintmax(nb, e);
	e->printchar = (e->zero && e->pointlen == -1) ? '0' : ' ';
	calc_printextra(e);
	str = ft_atoi_uintmax(nb, e);
	cutu(e, str);
	e->printlen = (e->len >= e->pointlen) ? e->len : e->pointlen;
	if ((e->printlen + e->printextra >= e->width || e->printchar == '0' \
				|| e->align) && e->printextra > 0)
		ft_printprefix(e);
	if (e->printlen + e->printextra < e->width && !e->align)
		ft_printspace(e->width - (e->printlen + e->printextra), \
				e->printchar, e);
	if (e->printlen + e->printextra < e->width && !e->align && e->printchar \
			== ' ' && e->printextra)
		ft_printprefix(e);
	printpointlen(e, str);
	if (!(e->pointlen != -1 && *str == '0'))
		e->totcount += ft_putstr_count(str);
	if (e->pointlen != -1 && *str == '0' && \
			(e->type == OCTAL || e->type == UOCTAL) && e->hash)
		e->totcount += ft_putstr_count(str);
	nb_post_flags(e);
}
