/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wbyteslen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:03:00 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/19 16:59:16 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wbyteslen(const wchar_t *ws)
{
	size_t	len;

	len = 0;
	while (*ws)
	{
		if (*ws <= ft_atoi_base("7F", 16))
			len++;
		else if (*ws <= ft_atoi_base("7FF", 16))
			len += 2;
		else if (*ws <= ft_atoi_base("FFFF", 16))
			len += 3;
		else if (*ws <= ft_atoi_base("10FFFF", 16))
			len += 4;
		ws++;
	}
	return (len);
}
