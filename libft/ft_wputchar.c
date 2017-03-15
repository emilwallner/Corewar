/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:48:09 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 17:48:36 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putwchar2(wchar_t c, unsigned char byte)
{
	static unsigned short	mask[] = {128, 192, 224, 240, 63};

	if (c <= ft_atoi_base("FFFF", 16))
	{
		byte = mask[2] + (c >> 12);
		write(1, &byte, 1);
		byte = mask[0] + ((c >> 6) & mask[4]);
		write(1, &byte, 1);
		byte = mask[0] + (c & mask[4]);
		write(1, &byte, 1);
		return (3);
	}
	else if (c <= ft_atoi_base("10FFFF", 16))
	{
		byte = mask[3] + (c >> 18);
		write(1, &byte, 1);
		byte = mask[0] + ((c >> 12) & mask[4]);
		write(1, &byte, 1);
		byte = mask[0] + ((c >> 6) & mask[4]);
		write(1, &byte, 1);
		byte = mask[0] + (c & mask[4]);
		write(1, &byte, 1);
		return (4);
	}
	return (0);
}

int			ft_wputchar(wchar_t c)
{
	static unsigned short	mask[] = {128, 192, 224, 240, 63};
	unsigned char			byte;

	if (c >= ft_atoi_base("D800", 16) && c <= ft_atoi_base("DFFF", 16))
		return (0);
	if (!c)
		return (1);
	byte = 0;
	if (c <= ft_atoi_base("7F", 16))
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c <= ft_atoi_base("7FF", 16))
	{
		byte = mask[1] + (c >> 6);
		write(1, &byte, 1);
		byte = mask[0] + (c & mask[4]);
		write(1, &byte, 1);
		return (2);
	}
	else if (c <= ft_atoi_base("10FFFF", 16))
		return (ft_putwchar2(c, 0));
	return (0);
}
