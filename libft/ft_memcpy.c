/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:09:11 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/19 10:17:10 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*pd;
	const char	*ps;

	i = 0;
	pd = dest;
	ps = src;
	while (n--)
	{
		*(pd + i) = *(ps + i);
		i++;
	}
	return (dest);
}
