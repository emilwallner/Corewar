/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:09:25 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 12:19:45 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "stdio.h"

void	calc_wsize(wchar_t *str, int *len, int *totlen, int *i)
{
	int		charlen;
	int		end;

	charlen = 0;
	end = 0;
	while (str[*len] && *totlen <= *i && end != 1)
	{
		charlen = wchars_size(str[*len]);
		if ((charlen + *totlen) <= *i)
		{
			*totlen += charlen;
			charlen = 0;
		}
		if (charlen + *totlen >= *i)
			end = 1;
		*len = *len + 1;
	}
}

int		wstrings_size(wchar_t *str, int i)
{
	int		len;
	int		totlen;

	totlen = 0;
	len = 0;
	if (!str)
		return (6);
	if (i == -1)
	{
		while (str[len])
		{
			totlen += (wchars_size(str[len]));
			len++;
		}
	}
	else
		calc_wsize(str, &len, &totlen, &i);
	return (totlen);
}

void	ft_putwstr_cut(wchar_t *str, int i)
{
	int		len;
	int		totlen;
	int		charlen;
	int		end;

	end = 0;
	totlen = 0;
	charlen = 0;
	len = 0;
	if (!str)
		str = L"(null)";
	while (str[len] != '\0' && totlen <= i && end != 1)
	{
		charlen = (wchars_size(str[len]));
		if (totlen + charlen <= i)
		{
			ft_printwchar(str[len]);
			totlen += charlen;
			charlen = 0;
		}
		if (charlen + totlen >= i)
			end = 1;
		len++;
	}
}

void	wstrings(wchar_t *str, t_vars *e)
{
	e->printlen = wstrings_size(str, e->pointlen);
	if (e->width < e->printlen)
		ft_putwstr_cut(str, e->printlen);
	if (e->width > e->printlen && e->align == TRUE)
	{
		ft_putwstr_cut(str, e->printlen);
		ft_printspace(e->width - e->printlen, ' ', e);
	}
	if (e->width > e->printlen && e->align == FALSE)
	{
		ft_printspace(e->width - e->printlen, ' ', e);
		ft_putwstr_cut(str, e->printlen);
	}
	e->totcount += e->printlen;
}
