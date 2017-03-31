/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:22:51 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 11:05:15 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include "ft_print.h"
#include "libft.h"

void		ftprint(va_list ap, t_vars *e)
{
	(e->f == 1) ? n((va_arg(ap, int)), e) : 0;
	(e->f == 2) ? n((signed char)(va_arg(ap, int)), e) : 0;
	(e->f == 3) ? n((short int)(va_arg(ap, int)), e) : 0;
	(e->f == 4) ? n((va_arg(ap, long long int)), e) : 0;
	(e->f == 5) ? n((va_arg(ap, long int)), e) : 0;
	(e->f == 6) ? n((va_arg(ap, intmax_t)), e) : 0;
	(e->f == 7) ? n((va_arg(ap, size_t)), e) : 0;
	(e->f == 8) ? u((va_arg(ap, unsigned int)), e) : 0;
	(e->f == 9) ? u((unsigned char)va_arg(ap, unsigned int), e) : 0;
	(e->f == 10) ? u((unsigned short int)(va_arg(ap, unsigned int)), e) : 0;
	(e->f == 11) ? u((va_arg(ap, unsigned long int)), e) : 0;
	(e->f == 12) ? u((va_arg(ap, unsigned long long int)), e) : 0;
	(e->f == 13) ? u((va_arg(ap, uintmax_t)), e) : 0;
	(e->f == 14) ? u((va_arg(ap, size_t)), e) : 0;
	(e->f == 15) ? chars((char)(va_arg(ap, int)), e) : 0;
	(e->f == 16) ? wchars((wchar_t)(va_arg(ap, wint_t)), e) : 0;
	(e->f == 17) ? strings((va_arg(ap, char*)), e) : 0;
	(e->f == 18) ? wstrings((va_arg(ap, wchar_t*)), e) : 0;
	(e->f == 19) ? u((va_arg(ap, unsigned long int)), e) : 0;
	(e->f == 20) ? percent(e) : 0;
}

void		typeformat(t_vars *e)
{
	((e->type < 3) && e->flags == 0) ? e->f = 1 : 0;
	((e->type < 3) && e->flags == 1) ? e->f = 2 : 0;
	((e->type < 3) && e->flags == 2) ? e->f = 3 : 0;
	((e->type < 3) && e->flags == 3) ? e->f = 4 : 0;
	((e->type < 3) && e->flags == 4) ? e->f = 5 : 0;
	((e->type < 3) && e->flags == 5) ? e->f = 6 : 0;
	((e->type < 3) && e->flags == 6) ? e->f = 7 : 0;
	((e->type > 8) && e->flags == 0) ? e->f = 8 : 0;
	((e->type > 8) && e->flags == 1) ? e->f = 9 : 0;
	((e->type > 8) && e->flags == 2) ? e->f = 10 : 0;
	((e->type > 8) && e->flags == 3) ? e->f = 11 : 0;
	((e->type > 8) && e->flags == 4) ? e->f = 12 : 0;
	((e->type > 8) && e->flags == 5) ? e->f = 13 : 0;
	((e->type > 8) && e->flags == 6) ? e->f = 14 : 0;
	(e->type == CHAR && e->flags == 0) ? e->f = 15 : 0;
	((e->type == CHAR && e->flags == 4) || e->type == WCHAR) ? e->f = 16 : 0;
	(e->type == STRING && e->flags == 0) ? e->f = 17 : 0;
	((e->type == STRING && e->flags == 4) || e->type == WSTRING) \
			? e->f = 18 : 0;
	(e->type == POINTER) ? e->f = 19 : 0;
	(e->type == PERCENT) ? e->f = 20 : 0;
	(e->type == UUNSIGNED || e->type == UOCTAL) ? e->f = 11 : 0;
	(e->type == UDECIMAL) ? e->f = 5 : 0;
}
