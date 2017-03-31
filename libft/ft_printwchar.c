/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:41:15 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 11:49:22 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_print.h"

int		wchars_size(wchar_t c)
{
	if (c > 55295 && c < 57344)
		exit(-1);
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 1114112)
		return (4);
	else
		exit(-1);
	return (0);
}

void	ft_printwchar_norm(wchar_t c, unsigned char bit)
{
	bit = 240 | (c >> 18 & 7);
	write(1, &bit, 1);
	bit = 128 | (c >> 12 & 63);
	write(1, &bit, 1);
	bit = 128 | (c >> 6 & 63);
	write(1, &bit, 1);
	bit = 128 | (c & 63);
	write(1, &bit, 1);
}

void	ft_printwchar(wchar_t c)
{
	unsigned char	bit;

	bit = '\0';
	if (c < 128)
	{
		write(1, &c, 1);
	}
	else if (c < 2048)
	{
		bit = (c >> 6) | 192;
		write(1, &bit, 1);
		bit = 128 | (c & 63);
		write(1, &bit, 1);
	}
	else if (c < 65536)
	{
		bit = 224 | (c >> 12 & 15);
		write(1, &bit, 1);
		bit = (128 | (c >> 6 & 63));
		write(1, &bit, 1);
		bit = (128 | (c & 63));
		write(1, &bit, 1);
	}
	else if (c < 1114112)
		ft_printwchar_norm(c, bit);
}

void	wchars(wchar_t c, t_vars *e)
{
	e->len = wchars_size(c);
	if (e->width < e->len)
	{
		ft_printwchar(c);
		e->totcount += e->len;
	}
	if (e->width > e->len && e->align == FALSE)
	{
		ft_printspace(e->width - e->len, ' ', e);
		ft_printwchar(c);
		e->totcount += e->len;
	}
	if (e->width > e->len && e->align == TRUE)
	{
		ft_printwchar(c);
		e->totcount += e->len;
		ft_printspace(e->width - e->len, ' ', e);
	}
}
