/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wgetchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:48:09 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 17:44:12 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_wgetchar2(wchar_t c, char *wstr)
{
	static unsigned short	mask[] = {128, 192, 224, 240, 63};

	if (c <= ft_atoi_base("FFFF", 16))
	{
		wstr[0] = mask[2] + (c >> 12);
		wstr[1] = mask[0] + ((c >> 6) & mask[4]);
		wstr[2] = mask[0] + (c & mask[4]);
		wstr[3] = '\0';
	}
	else if (c <= ft_atoi_base("10FFFF", 16))
	{
		wstr[0] = mask[3] + (c >> 18);
		wstr[1] = mask[0] + ((c >> 12) & mask[4]);
		wstr[2] = mask[0] + ((c >> 6) & mask[4]);
		wstr[3] = mask[0] + (c & mask[4]);
		wstr[4] = '\0';
	}
}

char		*ft_wgetchar(wchar_t c)
{
	static unsigned short	mask[] = {128, 192, 224, 240, 63};
	char					*wstr;

	if (!(wstr = ft_strnew(4)))
		return (NULL);
	if (c <= ft_atoi_base("7F", 16))
	{
		wstr[0] = c;
		wstr[1] = '\0';
	}
	else if (c <= ft_atoi_base("7FF", 16))
	{
		wstr[0] = mask[1] + (c >> 6);
		wstr[1] = mask[0] + (c & mask[4]);
		wstr[2] = '\0';
	}
	else if (c > ft_atoi_base("U+DFFF", 16) && c <= ft_atoi_base("10FFFF", 16))
		ft_wgetchar2(c, wstr);
	return (wstr);
}
