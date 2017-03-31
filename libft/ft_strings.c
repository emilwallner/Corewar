/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:31:03 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 11:49:55 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "stdio.h"

int		ft_putstr_count(char *str)
{
	int		i;

	i = 0;
	if (!str)
		ft_putstr_count("(null)");
	else
		while (*str)
		{
			ft_putchar(*str);
			i++;
			str++;
		}
	return (i);
}

void	ft_putstr_cut(char *str, int width, t_vars *e)
{
	int		i;

	i = 0;
	while (i < width && *str)
	{
		e->totcount += ft_putchar_count(*str);
		i++;
		str++;
	}
}

void	strings(char *str, t_vars *e)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (e->pointlen < len && e->pointlen != -1)
		e->printlen = e->pointlen;
	else
		e->printlen = len;
	if (e->width <= e->printlen)
		ft_putstr_cut(str, e->printlen, e);
	else if (e->width > e->printlen && e->align == TRUE)
	{
		ft_putstr_cut(str, e->printlen, e);
		ft_printspace(e->width - e->printlen, ' ', e);
	}
	else if (e->width > e->printlen && e->align == FALSE)
	{
		ft_printspace(e->width - e->printlen, ' ', e);
		ft_putstr_cut(str, e->printlen, e);
	}
}
