/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:07:31 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/28 17:20:42 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char*)s;
	i = 0;
	while (n--)
	{
		*(p + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
