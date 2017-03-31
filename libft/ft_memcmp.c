/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:28:30 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/15 17:11:27 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1t;
	unsigned char	*str2t;

	i = 0;
	str1t = (unsigned char *)str1;
	str2t = (unsigned char *)str2;
	while (i < n)
	{
		if (str1t[i] != str2t[i])
			return (str1t[i] - str2t[i]);
		i++;
	}
	return (0);
}
