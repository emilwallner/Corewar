/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:35:49 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/17 19:55:36 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	size_t				i;

	ps = src;
	pd = dst;
	if (pd > ps && (size_t)(pd - ps) <= len)
		while (len--)
			pd[len] = ps[len];
	else
	{
		i = -1;
		while (++i < len)
			pd[i] = ps[i];
	}
	return (dst);
}
