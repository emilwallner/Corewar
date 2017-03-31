/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:25:37 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 15:55:08 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_print.h"

char	*print_mainstring(char *str, t_vars *e)
{
	e->totcount += ft_putchar_count(*str);
	str++;
	return (str);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	t_vars	e;

	e.totcount = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
			str = print_mainstring(str, &e);
		else
		{
			str++;
			ft_initialize_e(&e);
			str = ft_printtype(str, &e);
			if (ft_error_handle(&e))
				return (-1);
			typeformat(&e);
			ftprint(ap, &e);
			if (e.nb)
				free(e.nb);
			e.nb = NULL;
		}
	}
	va_end(ap);
	return (e.totcount);
}
